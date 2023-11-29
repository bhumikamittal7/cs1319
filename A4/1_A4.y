/* test file from slide 06.14 */
%{
#include <string>
#include <stdio.h>
#include "1_A4_translator.h"
#include <iostream>              
#include <cstdlib>

extern int yylex();
void yyerror(const char *s);
extern string var_type;

using namespace std;
%}

//detailed error messages
// %define parse.error verbose
/* ==================================== UNION =============================================== */

%union {
        char *charValue;
        int intValue;
        int instrCounter;
        int paramCount;

        symbolType *symType;
        sym* symPtr;
        Array *A;

        Expression *E;
        Statement *S;

        char unaryOp;
}
/* ==================================== TOKENS =============================================== */

%token <symPtr> IDENTIFIER

%token <intValue> INTEGER_CONSTANT
%token <charValue> CHARACTER_CONSTANT
%token <charValue> STRING_LITERAL

%token VOID CHAR INT IF ELSE FOR RETURN 
%token L_SQUARE_BRACKET R_SQUARE_BRACKET L_ROUND_BRACKET R_ROUND_BRACKET L_CURLY_BRACKET R_CURLY_BRACKET 
%token ARROW AMPERSAND ASTERISK PLUS MINUS DIVIDE MODULO NOT QUESTION 
%token LESS_THAN GREATER_THAN LESS_THAN_EQUAL_TO GREATER_THAN_EQUAL_TO EQUAL_TO NOT_EQUAL_TO 
%token LOGICAL_AND LOGICAL_OR ASSIGN COLON SEMICOLON COMMA INVALID_TOKEN

%start translation_unit;

%right "then" ELSE              //dangling else handled hopefully (are we suppose to this though?)

/* ==================================== Type stuff  =============================================== */
%type <unaryOp> unary_operator
%type <paramCount> argument_expression_list argument_expression_list_opt
%type <E> 
        expression 
        assignment_expression 
        conditional_expression 
        logical_OR_expression 
        logical_AND_expression 
        equality_expression 
        relational_expression 
        additive_expression 
        multiplicative_expression 
        primary_expression
        expression_statement 


%type <S>
        statement 
        selection_statement 
        iteration_statement 
        jump_statement 
        compound_statement 
        block_item 
        block_item_list 
        block_item_list_opt

%type <symType> pointer

%type <symPtr> initializer
%type <symPtr> direct_declarator init_declarator declarator

%type<A> postfix_expression
	unary_expression

/* =================== Auxillary non-terminals M and N used for backpatching =================== */
%type <instrCounter> M 
%type <S> N

%%

M: %empty { $$ = instrCounter; }
        ;

N: %empty { 
        $$ = new Statement();
        $$ -> nextList = makeList(nextInstr());
        emit("goto", "");
         
}

/* ===================================== 1. Expressions =====================================*/

constant: INTEGER_CONSTANT 
        {
		$$=new Expression();	
		updateNextInstr();
		string p=convertToString($1);
		updateNextInstr();
		$$->loc=gentemp(new symbolType("INTEGER"),p);
		updateNextInstr();
		emit("=",$$->loc->name,p);
		updateNextInstr();
        }
        | CHARACTER_CONSTANT
        {
		$$=new Expression();
		updateNextInstr();
		$$->loc=gentemp(new symbolType("CHAR"),$1);
		updateNextInstr();
		emit("=",$$->loc->name,string($1));
		updateNextInstr();
        }
        ;

primary_expression : IDENTIFIER 
                        {
                                $$ = new Expression();
                                updateNextInstr();
                                $$ -> loc = $1;
                                updateNextInstr();
                                $$->type = "not-boolean";
                                updateNextInstr();
                        }
                    | constant 
                        {
                                $$ = $1;
                        }
                    | STRING_LITERAL    
                    {
                        $$=new Expression();
                        updateNextInstr();
                        $$->loc=gentemp(new symbolType("PTR"),$1);
                        updateNextInstr();
                        $$->loc->type->arrtype=new symbolType("CHAR");
                        updateNextInstr();
                        
                    }
                    | L_ROUND_BRACKET expression R_ROUND_BRACKET
                        {
                                $$ = $2;
                        }
                    ;

argument_expression_list_opt: argument_expression_list  { $$=$1; }  
                            | %empty{ $$=0; } 
                            ;

postfix_expression: primary_expression
                        {
                                $$=new Array();
                                updateNextInstr();
                                $$->Array=$1->loc;	
                                updateNextInstr();
                                $$->type=$1->loc->type;	
                                updateNextInstr();
                                $$->loc=$$->Array;
                                updateNextInstr();
                        }

                    | postfix_expression L_SQUARE_BRACKET expression R_SQUARE_BRACKET
                { 	
                                
                        $$=new Array();
                        updateNextInstr();
                        $$->type=$1->type->arrtype;				// type=type of element	
                        updateNextInstr();			
                        $$->Array=$1->Array;						// copy the base
                        updateNextInstr();
                        $$->loc=gentemp(new symbolType("INTEGER"));		// store computed address
                        updateNextInstr();
                        $$->aType="ARR";						//aType is ARR.
                        updateNextInstr();
                        INTEGER p=sizeOfType($$->type);
                        updateNextInstr();
                        string str=convertToString(p);
                        updateNextInstr();
                        emit("*",$$->loc->name,$3->loc->name,str);
                        updateNextInstr();
	        }
                    | postfix_expression L_ROUND_BRACKET argument_expression_list_opt R_ROUND_BRACKET
                    {
                        $$=new Array();	
                        updateNextInstr();
                        $$->Array=gentemp($1->type);
                        updateNextInstr();
                        string str=convertToString($3);
                        updateNextInstr();
                        emit("call",$$->Array->name,$1->Array->name,str);
                        updateNextInstr();
                    }
                    | postfix_expression ARROW IDENTIFIER {  }/* pointer indirection only one level */
                    ;

argument_expression_list: assignment_expression
                        {
                                $$ = $1;
                                updateNextInstr();
                                emit("param",$1->loc->name);	
                                updateNextInstr();
                        }
                        | argument_expression_list COMMA assignment_expression
                        {
                                $$ = $1+1;
                                updateNextInstr();
                                emit("param",$3->loc->name);	
                                updateNextInstr();
                        }
                        ;

unary_expression: postfix_expression { $$=$1; } 	
                | unary_operator unary_expression
                {			

                        $$=new Array();
                        updateNextInstr();
                        switch($1)
                                {	  
                                        case '+':  
                                                $$=$2;
                                                break;                    //unary plus, do nothing
                                        case '-':				   //unary minus, generate new temporary of the same base type and make it negative of current one
                                                $$->Array=gentemp(new symbolType($2->Array->type->type));
                                                updateNextInstr();
                                                emit("uminus",$$->Array->name,$2->Array->name);
                                                updateNextInstr();
                                                break; 

                                        case '!':				//logical not, generate new temporary of the same base type and make it negative of current one
                                                $$->Array=gentemp(new symbolType($2->Array->type->type));
                                                updateNextInstr();
                                                emit("!",$$->Array->name,$2->Array->name);
                                                updateNextInstr();
                                                break;
                                }
                }
                ;

unary_operator: AMPERSAND
                {
                        $$ = '&';
                }
                | ASTERISK
                {
                        $$ = '*';
                }
                | PLUS
                {
                        $$ = '+';
                }
                | MINUS   
                {
                        $$ = '-';
                }
                | NOT 
                {
                        $$ = '!';
                }
                ;

multiplicative_expression: unary_expression     /* these are left associative */    
                                {
                                        $$ = $1;
                                }
                            | multiplicative_expression ASTERISK unary_expression   
                            	{ 
		 
		if(!compareSymbolType($1->loc, $3->Array))         
			cout<<"Type Error in Program"<< endl;	// error
		else 								 //if types are compatible, generate new temporary and equate to the product
		{
			$$ = new Expression();	
			updateNextInstr();
			$$->loc = gentemp(new symbolType($1->loc->type->type));
			updateNextInstr();
			emit("*", $$->loc->name, $1->loc->name, $3->Array->name);
			updateNextInstr();
			 
		}
	}
                            | multiplicative_expression DIVIDE unary_expression     
                            	{
		 
		if(!compareSymbolType($1->loc, $3->Array))
			cout << "Type Error in Program"<< endl;
		else    //if types are compatible, generate new temporary and equate to the quotient
		{
			$$ = new Expression();
			updateNextInstr();
			$$->loc = gentemp(new symbolType($1->loc->type->type));
			updateNextInstr();
			emit("/", $$->loc->name, $1->loc->name, $3->Array->name);
			updateNextInstr();	
			 						
		}
	}
                            | multiplicative_expression MODULO unary_expression     
                            	{
		 
		if(!compareSymbolType($1->loc, $3->Array))
			cout << "Type Error in Program"<< endl;		
		else 		 //if types are compatible, generate new temporary and equate to the quotient
		{
			$$ = new Expression();
			updateNextInstr();
			$$->loc = gentemp(new symbolType($1->loc->type->type));
			updateNextInstr();
			emit("%", $$->loc->name, $1->loc->name, $3->Array->name);	
			updateNextInstr();	
			 	
		}
	}
                            ;

additive_expression: multiplicative_expression  /* these are left associative */    
                        {
                                $$ = $1;
                        }
                    | additive_expression PLUS multiplicative_expression   
                    	{
		 
		if(!compareSymbolType($1->loc, $3->loc))
			cout << "Type Error in Program"<< endl;
		else    	//if types are compatible, generate new temporary and equate to the sum
		{
			$$ = new Expression();	
			updateNextInstr();
			$$->loc = gentemp(new symbolType($1->loc->type->type));
			updateNextInstr();
			emit("+", $$->loc->name, $1->loc->name, $3->loc->name);
			updateNextInstr();
			 
		}
	}             
                    | additive_expression MINUS multiplicative_expression      
                    	{
		 
		if(!compareSymbolType($1->loc, $3->loc))
			cout << "Type Error in Program"<< endl;		
		else        //if types are compatible, generate new temporary and equate to the difference
		{	
			$$ = new Expression();	
			updateNextInstr();
			$$->loc = gentemp(new symbolType($1->loc->type->type));
			updateNextInstr();
			emit("-", $$->loc->name, $1->loc->name, $3->loc->name);
			updateNextInstr();
			 
		}
	}         
                    ;

relational_expression: additive_expression      /* these are left associative */        
                        {
                                $$ = $1;
                        }
                        | relational_expression LESS_THAN additive_expression  
                        	{
		if(!compareSymbolType($1->loc, $3->loc)) 
		{
			 
			cout << "Type Error in Program"<< endl;
		}
		else 
		{      //check compatible types		
			 							
			$$ = new Expression();
			updateNextInstr();
			$$->type = "BOOL";                         //new type is boolean
			updateNextInstr();		
			$$->trueList = makelist(nextInstr());     //makelist for trueList and falseList
			updateNextInstr();
			$$->falseList = makelist(nextInstr()+1);
			updateNextInstr();
			emit("<", "", $1->loc->name, $3->loc->name);     //emit statement if a<b GOTO .. 
			updateNextInstr();
			 
			emit("GOTO", "");	//emit statement GOTO ..
			updateNextInstr();
			 
		}
	}         
                        | relational_expression GREATER_THAN additive_expression    
                        	{
		if(!compareSymbolType($1->loc, $3->loc)) 
		{
			 
			cout << "Type Error in Program"<< endl;
		}
		else 
		{
			 
			$$ = new Expression();	
			updateNextInstr();
			$$->type = "BOOL";
			updateNextInstr();
			$$->trueList = makelist(nextInstr());
			updateNextInstr();
			$$->falseList = makelist(nextInstr()+1);
			updateNextInstr();
			emit(">", "", $1->loc->name, $3->loc->name);
			updateNextInstr();
			 
			emit("GOTO", "");
			updateNextInstr();
			 
		}	
	}    
                        | relational_expression LESS_THAN_EQUAL_TO additive_expression
                        	{
		if(!compareSymbolType($1->loc, $3->loc)) 
		{
			 
			cout << "Type Error in Program"<< endl;
		}
		else 
		{		
			 
			$$ = new Expression();		
			updateNextInstr();
			$$->type = "BOOL";
			updateNextInstr();
			$$->trueList = makelist(nextInstr());
			updateNextInstr();
			$$->falseList = makelist(nextInstr()+1);
			updateNextInstr();
			emit("<=", "", $1->loc->name, $3->loc->name);
			updateNextInstr();
			 
			emit("GOTO", "");
			updateNextInstr();
			 
		}		
	}  
                        | relational_expression GREATER_THAN_EQUAL_TO additive_expression
                        ;

equality_expression: relational_expression      /* these are left associative */ 
                        {
                                $$ = $1;
                        }
                    | equality_expression EQUAL_TO relational_expression     
                    {
		if(!compareSymbolType($1->loc, $3->loc))                //check compatible types
		{
			 
			cout << "Type Error in Program"<< endl;
		}
		else 
		{
			 
			convertBool2Int($1);                  //convert BOOL to INTEGER
			updateNextInstr();	
			convertBool2Int($3);
			updateNextInstr();
			$$ = new Expression();
			updateNextInstr();
			$$->type = "BOOL";
			updateNextInstr();
			$$->trueList = makelist(nextInstr());            //make lists for new expression
			updateNextInstr();
			$$->falseList = makelist(nextInstr()+1); 
			updateNextInstr();
			emit("==", "", $1->loc->name, $3->loc->name);      //emit if a==b GOTO ..
			updateNextInstr();
			 
			emit("GOTO", "");				//emit GOTO ..
			updateNextInstr();
			 
		}
		
	}           
                    | equality_expression NOT_EQUAL_TO relational_expression   
                    {
		if(!compareSymbolType($1->loc, $3->loc)) 
		{
			 
			cout << "Type Error in Program"<< endl;
		}
		else 
		{			
			 
			convertBool2Int($1);	
			updateNextInstr();
			convertBool2Int($3);
			updateNextInstr();
			$$ = new Expression();                 //result is boolean
			updateNextInstr();
			$$->type = "BOOL";
			updateNextInstr();
			$$->trueList = makelist(nextInstr());
			updateNextInstr();
			$$->falseList = makelist(nextInstr()+1);
			updateNextInstr();
			emit("!=", "", $1->loc->name, $3->loc->name);
			updateNextInstr();
			 
			emit("GOTO", "");
			updateNextInstr();
			 
		}
	}        
                    ;       

logical_AND_expression: equality_expression  { $$=$1; }	   /* these are left associative */       
                        | logical_AND_expression N LOGICAL_AND M equality_expression       
                            	{ 
		 
		convertInt2Bool($5);         //convert inclusive_or_expression INTEGER to BOOL
		updateNextInstr();
		backpatch($2->nextList, nextInstr());        //$2->nextList goes to next instruction
		updateNextInstr();
		convertInt2Bool($1);                  //convert logical_and_expression to BOOL
		updateNextInstr();
		$$ = new Expression();     //make new boolean expression 
		updateNextInstr();
		$$->type = "BOOL";
		updateNextInstr();
		backpatch($1->trueList, $4);        //if $1 is true, we move to $5
		updateNextInstr();
		$$->trueList = $5->trueList;        //if $5 is also true, we get trueList for $$
		updateNextInstr();
		$$->falseList = merge($1->falseList, $5->falseList);    //merge their falselists
		updateNextInstr();
		 
	}    
                        ;   

logical_OR_expression: logical_AND_expression   /* these are left associative */   
                        {
                                $$ = $1;
                        }
                        | logical_OR_expression N LOGICAL_OR M logical_AND_expression     
                         	{ 
		 
		convertInt2Bool($5);			 //convert logical_and_expression INTEGER to BOOL
		updateNextInstr();
		backpatch($2->nextList, nextInstr());	//$2->nextList goes to next instruction
		updateNextInstr();
		convertInt2Bool($1);			//convert logical_or_expression to BOOL
		updateNextInstr();
		$$ = new Expression();			//make new boolean expression
		updateNextInstr();
		$$->type = "BOOL";
		updateNextInstr();
		backpatch($1->falseList, $4);		//if $1 is true, we move to $5
		updateNextInstr();
		$$->trueList = merge($1->trueList, $5->trueList);		//merge their truelists
		updateNextInstr();
		$$->falseList = $5->falseList;		 	//if $5 is also false, we get falseList for $$
		updateNextInstr();
		 
	}
                        ;

conditional_expression: logical_OR_expression   /* these are right associative */      
                        {
                                $$ = $1;
                        }
                        | logical_OR_expression N QUESTION M expression N COLON M conditional_expression    
                        {
		 
		//normal conversion method to get conditional expressions
		$$->loc = gentemp($5->loc->type);       //generate temporary for expression
		updateNextInstr();
		$$->loc->update($5->loc->type);
		updateNextInstr();
		emit("=", $$->loc->name, $9->loc->name);      //make it equal to sconditional_expression
		updateNextInstr();
		 
		list<int> l = makelist(nextInstr());        //makelist next instruction
		emit("GOTO", "");              //prevent fallthrough
		updateNextInstr();
		 
		backpatch($6->nextList, nextInstr());        //after N, go to next instruction
		updateNextInstr();
		emit("=", $$->loc->name, $5->loc->name);
		updateNextInstr();
		 
		list<int> m = makelist(nextInstr());         //makelist next instruction
		updateNextInstr();
		l = merge(l, m);						//merge the two lists
		updateNextInstr();
		emit("GOTO", "");						//prevent fallthrough
		updateNextInstr();
		 
		backpatch($2->nextList, nextInstr());   //backpatching
		updateNextInstr();
		convertInt2Bool($1);                   //convert expression to boolean
		updateNextInstr();
		backpatch($1->trueList, $4);           //$1 true goes to expression
		updateNextInstr();
		backpatch($1->falseList, $8);          //$1 false goes to conditional_expression
		updateNextInstr();
		backpatch(l, nextInstr());
		updateNextInstr();
		 
	}
                        ;

assignment_expression: conditional_expression   /* these are right associative */      
                        {
                                $$ = $1;
                        }
                        | unary_expression ASSIGN assignment_expression  
                        	 {
		if($1->aType=="ARR")       //if type is ARR, simply check if we need to convert and emit
		{
			 
			$3->loc = convertType($3->loc, $1->type->type);
			updateNextInstr();
			emit("[]=", $1->Array->name, $1->loc->name, $3->loc->name);		
			updateNextInstr();
			 
		}
		else if($1->aType=="PTR")     //if type is PTR, simply emit
		{
			 
			emit("*=", $1->Array->name, $3->loc->name);		
			updateNextInstr();
			 
		}
		else                              //otherwise assignment
		{
			 
			$3->loc = convertType($3->loc, $1->Array->type->type);
			emit("=", $1->Array->name, $3->loc->name);
			updateNextInstr();
			 
		}
		
		$$ = $3;
		 
		
	}              
                        ;

expression: assignment_expression
                {
                        $$ = $1;
                }
            ;

/* ===================================== 2. Declarations =====================================*/

declaration: type_specifier init_declarator SEMICOLON   {       }
            ;

init_declarator: declarator {$$=$1;}
                | declarator ASSIGN initializer 
                	{
		 
		if($3->val!="") $1->val=$3->val;        //get the initial value and  emit it
		emit("=", $1->name, $3->name);
		updateNextInstr();
		 
	}
                ;

type_specifier: VOID    {var_type="VOID";}
                | CHAR  { var_type="CHAR"; }
                | INT   { var_type="INTEGER"; }
                ;


declarator: pointer direct_declarator 
	{
		 
		symbolType *t = $1;
		updateNextInstr();
		while(t->arrtype!=NULL) t = t->arrtype;           //for multidimensional arr1s, move in depth till you get the base type
		updateNextInstr();
		t->arrtype = $2->type;                //add the base type 
		updateNextInstr();
		$$ = $2->update($1);                  //update
		updateNextInstr();
		 
	}
        | direct_declarator { }
            ;

parameter_list_opt: parameter_list          
                    | %empty               
                    ;

direct_declarator: IDENTIFIER       
	{
		 
		$$ = $1->update(new symbolType(var_type));
		updateNextInstr();
		currSymbolPtr = $$;
		updateNextInstr();
		 
		
	}
                    | IDENTIFIER L_SQUARE_BRACKET INTEGER_CONSTANT R_SQUARE_BRACKET  
                    | IDENTIFIER L_ROUND_BRACKET parameter_list_opt R_ROUND_BRACKET  
                    ;

pointer: ASTERISK   
	{ 
		$$ = new symbolType("PTR",$3);
		updateNextInstr();
		  
	}
        ;

parameter_list: parameter_declaration           {       }
                | parameter_list COMMA parameter_declaration {  }
                ;

identifier_opt: IDENTIFIER  
                | %empty   
                ;

parameter_declaration: type_specifier pointer identifier_opt   
                        ;

initializer: assignment_expression   { $$=$1->loc; }  
            ;

/* ===================================== 3. Statements =====================================*/

statement: compound_statement 
                {
                        $$ = $1;
                }
            | expression_statement 
				{ 
		$$=new Statement();              //create new statement with same nextList
		$$->nextList=$1->nextList; 
	}
            | selection_statement  
                {
                        $$ = $1;
                }
            | iteration_statement  
                {
                        $$ = $1;
                }
            | jump_statement    
                {
                        $$ = $1;
                }   
            ;

block_item_list_opt: block_item_list    
                {
                        $$ = $1;
                }
                    | %empty           { $$=new Statement(); } 
                    ;

compound_statement: L_CURLY_BRACKET block_item_list_opt R_CURLY_BRACKET  
                {
                        $$ = $2;
                }
                    ;   

block_item_list: block_item  
                {
                        $$ = $1;
                }  
                | block_item_list M block_item   
					{ 
						$$=$3;
						backpatch($1->nextList,$2);     //after $1, move to block_item via $2
					}
                ;

block_item: declaration  { $$=new Statement(); }
            | statement  
                {
                        $$ = $1;
                }
            ;

expression_opt: expression  
                {
                        $$ = $1;
                }
                | %empty     
                {
                        $$ = new Expression();
                }
                ;

expression_statement: expression_opt SEMICOLON  {       }
                    ;

selection_statement: IF L_ROUND_BRACKET expression N R_ROUND_BRACKET M statement N %prec "then"
						{
							backpatch($4->nextList, nextInstr());        //nextList of N goes to nextinstr
							updateNextInstr();
							convertInt2Bool($3);         //convert expression to BOOL
							updateNextInstr();
							$$ = new Statement();        //make new statement
							updateNextInstr();
							backpatch($3->trueList, $6);        //is expression is true, go to M i.e just before statement body
							updateNextInstr();
							list<int> temp = merge($3->falseList, $7->nextList);   //merge falseList of expression, nextList of statement and second N
							updateNextInstr();
							$$->nextList = merge($8->nextList, temp);
							updateNextInstr();
						}
                    | IF L_ROUND_BRACKET expression N R_ROUND_BRACKET M statement N ELSE M statement  
						{
							backpatch($4->nextList, nextInstr());		//nextList of N goes to nextinstr
							updateNextInstr();
							convertInt2Bool($3);        //convert expression to BOOL
							updateNextInstr();
							$$ = new Statement();       //make new statement
							updateNextInstr();
							backpatch($3->trueList, $6);    //when expression is true, go to M1 else go to M2
							updateNextInstr();
							backpatch($3->falseList, $10);
							updateNextInstr();
							list<int> temp = merge($7->nextList, $8->nextList);       //merge the nextlists of the statements and second N
							updateNextInstr();
							$$->nextList = merge($11->nextList,temp);	
							updateNextInstr();
						}
                    ;

iteration_statement: FOR L_ROUND_BRACKET expression_opt SEMICOLON M expression_opt SEMICOLON M expression_opt N R_ROUND_BRACKET M statement 
					{
						$$ = new Statement();
						updateNextInstr();
						convertInt2Bool($5);
						updateNextInstr();
						backpatch($5->trueList, $10);
						updateNextInstr();
						backpatch($8->nextList, $4);	//after N, go back to M1
						updateNextInstr();
						backpatch($11->nextList, $6);	//statement go back to expression
						updateNextInstr();
						string str=convertToString($6);
						updateNextInstr();
						emit("GOTO", str);				//prevent fallthrough
						updateNextInstr();

						$$->nextList = $5->falseList;	
						updateNextInstr();
					}
                    ;

jump_statement: RETURN expression_opt SEMICOLON
				{
					$$ = new Statement();
					updateNextInstr();
					emit("return", "");
					updateNextInstr();
				}
                ;

/* ===================================== 4. Translation Unit =====================================*/


translation_unit: external_declaration                  {   }
                | translation_unit external_declaration  {   }
                ;

external_declaration: function_definition       {   }
                    | declaration         {   }
                    ;

function_definition: type_specifier declarator compound_statement  
                        {
                            int nextInstr = 0;
							updateNextInstr();
							ST->parent=globalST;
							updateNextInstr();
							changeTable(globalST);                  
							updateNextInstr();
                        }
                    ;

%%

void yyerror(const char * s) {        //print syntax error
    cout<<s<<endl;
}
