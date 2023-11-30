/* test file from slide 06.14 */
%{
#include <string>
#include <stdio.h>
#include "1_A4_translator.h"
#include <iostream>              
#include <cstdlib>
#include <sstream>

extern string var_type;
extern int yylex();
void yyerror(const char *s);

using namespace std;
%}



%define parse.error verbose
/* ==================================== UNION =============================================== */

%union {
        char* char_value;
        int intval;
        int instrNum;
        int paramCount;

        symbolType* symType;
        sym* symPtr;
        Array *A;

        Expression* E;
        Statement* S;

        char unaryOp;
}
/* ==================================== TOKENS =============================================== */

%token <symPtr> IDENTIFIER

%token <intval> INTEGER_CONSTANT
%token <char_value> CHARACTER_CONSTANT
%token <char_value> STRING_LITERAL

%token VOID CHAR INT IF ELSE FOR RETURN 
%token L_SQUARE_BRACKET R_SQUARE_BRACKET L_ROUND_BRACKET R_ROUND_BRACKET L_CURLY_BRACKET R_CURLY_BRACKET 
%token ARROW AMPERSAND ASTERISK PLUS MINUS DIVIDE MODULO NOT QUESTION 
%token LESS_THAN GREATER_THAN LESS_THAN_EQUAL_TO GREATER_THAN_EQUAL_TO EQUAL_TO NOT_EQUAL_TO 
%token LOGICAL_AND LOGICAL_OR ASSIGN COLON SEMICOLON COMMA INVALID_TOKEN

%start translation_unit;


/* ==================================== Type stuff  =============================================== */
%type <unaryOp> unary_operator
%type <paramCount> argument_expression_list argument_expression_list_opt
%type <E> 
        expression 
		primary_expression
		multiplicative_expression
		additive_expression
		relational_expression
		equality_expression
		logical_AND_expression
		logical_OR_expression
		conditional_expression
		assignment_expression
		expression_statement

%type <S>
        statement 
		compound_statement
        selection_statement 
        iteration_statement 
        jump_statement  
        block_item 
        block_item_list 
        block_item_list_opt

%type <symType> pointer
%type <symPtr> initializer
%type <symPtr> direct_declarator init_declarator declarator

%type<A> postfix_expression
		unary_expression

/* =================== Auxillary non-terminals M and N used for backpatching =================== */
%type <instrNum> M 
%type <S> N

%%

M: %empty 
	{ 
		$$ = nextInstr(); 
	}
    ;

N: %empty { 
        $$ = new Statement();
        $$ -> nextList = makelist(nextInstr());
        emit("goto", "");
         
};

/* ===================================== 1. Expressions =====================================*/

primary_expression : IDENTIFIER 
                        {
							$$ = new Expression();
							updateNextInstr();
							$$ -> loc = $1;
							updateNextInstr();
							$$->type = "not-boolean";
							updateNextInstr();
                        }
                    | INTEGER_CONSTANT 
						{
							$$=new Expression();	
							updateNextInstr();
							string p=convertToString($1);
							updateNextInstr();
							$$->loc=gentemp(new symbolType("int"),p);
							updateNextInstr();
							emit("=",$$->loc->name,p);
							updateNextInstr();
						}
					| CHARACTER_CONSTANT
						{
							$$=new Expression();
							updateNextInstr();
							$$->loc=gentemp(new symbolType("char"),$1);
							updateNextInstr();
							emit("=",$$->loc->name,string($1));
							updateNextInstr();
						}
                    | STRING_LITERAL    
                    {
                        $$=new Expression();
                        updateNextInstr();
                        $$->loc=gentemp(new symbolType("ptr"),$1);
                        updateNextInstr();
                        $$->loc->type->arrtype=new symbolType("char");
                        updateNextInstr();
                        
                    }
                    | L_ROUND_BRACKET expression R_ROUND_BRACKET
                        {
                                $$ = $2;
                        }
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
						$$->type=$1->type->arrtype;				

						updateNextInstr();			
						$$->Array=$1->Array;						

						updateNextInstr();
						$$->loc=gentemp(new symbolType("int"));		

						updateNextInstr();
						$$->aType="arr";						

						updateNextInstr();
						if($1->aType=="arr") 
						{			
							
							sym* t=gentemp(new symbolType("int"));
							updateNextInstr();
							int p=sizeOfType($$->type);
							updateNextInstr();
							string str=convertToString(p);
							updateNextInstr();
							emit("*",t->name,$3->loc->name,str);
							updateNextInstr();	
							
							emit("+",$$->loc->name,$1->loc->name,t->name);
							updateNextInstr();
							
						}
						else 
						{                        

							int p=sizeOfType($$->type);
							updateNextInstr();
							string str=convertToString(p);
							updateNextInstr();
							emit("*",$$->loc->name,$3->loc->name,str);
							updateNextInstr();
							
						}
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

argument_expression_list_opt: argument_expression_list  { $$=$1; }  
                            | %empty{ $$=0; } 
                            ;

argument_expression_list: assignment_expression
                        {
                                $$ = 1;
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
                                                break;          
                                        case '-':				
                                                $$->Array=gentemp(new symbolType($2->Array->type->type));
                                                updateNextInstr();
                                                emit("uminus",$$->Array->name,$2->Array->name);
                                                updateNextInstr();
                                                break; 

                                        case '!':			
                                                $$->Array=gentemp(new symbolType($2->Array->type->type));
                                                updateNextInstr();
                                                emit("!",$$->Array->name,$2->Array->name);
                                                updateNextInstr();
                                                break;

										case '&':                                       

												
												$$->Array=gentemp((new symbolType("ptr")));
												updateNextInstr();
												$$->Array->type->arrtype=$2->Array->type; 
												updateNextInstr();
												emit("=&",$$->Array->name,$2->Array->name);
												updateNextInstr();
												break;
												
										case '*':                          

											$$->aType="ptr";
											updateNextInstr();
											$$->loc=gentemp($2->Array->type->arrtype);
											updateNextInstr();
											$$->Array=$2->Array;
											updateNextInstr();
											emit("=*",$$->loc->name,$2->Array->name);
											updateNextInstr();
											
											break;
						
                                }
                }
                ;

unary_operator: AMPERSAND
                {
                        $$ = '&';
						updateNextInstr();
                }
                | ASTERISK
                {
                        $$ = '*';
						updateNextInstr();
                }
                | PLUS
                {
                        $$ = '+';
						updateNextInstr();
                }
                | MINUS   
                {
                        $$ = '-';
						updateNextInstr();
                }
                | NOT 
                {
                        $$ = '!';
						updateNextInstr();
                }
                ;

multiplicative_expression: unary_expression    
                           {
		 
								$$ = new Expression();             
								updateNextInstr();						    
								if($1->aType=="arr") 			  
								{
									$$->loc = gentemp($1->loc->type);	
									updateNextInstr();
									emit("=[]", $$->loc->name, $1->Array->name, $1->loc->name);     

									updateNextInstr();
									
								}
								else if($1->aType=="ptr")         

								{ 
									$$->loc = $1->loc;        

									updateNextInstr();
									
								}
								else
								{
									$$->loc = $1->Array;
									updateNextInstr();
									
								}
							}

                            | multiplicative_expression ASTERISK unary_expression   
                            	{ 
			
									if(!compareSymbolType($1->loc, $3->Array))         
										cout<<"Type Error"<< endl;	
									else 								 
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
										cout << "Type Error"<< endl;
									else    
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
										cout << "Type Error"<< endl;		
									else 		
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
								cout << "Type Error"<< endl;
							else    
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
								cout << "Type Error"<< endl;		
							else       
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
								{      

																
									$$ = new Expression();
									updateNextInstr();
									$$->type = "bool";                         

									updateNextInstr();		
									$$->trueList = makelist(nextInstr());     

									updateNextInstr();
									$$->falseList = makelist(nextInstr()+1);
									updateNextInstr();
									emit("<", "", $1->loc->name, $3->loc->name);     

									updateNextInstr();
									
									emit("goto", "");	

									updateNextInstr();
									
								}
							}         
                        | relational_expression GREATER_THAN additive_expression    
                        	{
								if(!compareSymbolType($1->loc, $3->loc)) 
								{
									
									cout << "Type Error"<< endl;
								}
								else 
								{
									
									$$ = new Expression();	
									updateNextInstr();
									$$->type = "bool";
									updateNextInstr();
									$$->trueList = makelist(nextInstr());
									updateNextInstr();
									$$->falseList = makelist(nextInstr()+1);
									updateNextInstr();
									emit(">", "", $1->loc->name, $3->loc->name);
									updateNextInstr();
									
									emit("goto", "");
									updateNextInstr();
									
								}	
							}    
                        | relational_expression LESS_THAN_EQUAL_TO additive_expression
                        	{
								if(!compareSymbolType($1->loc, $3->loc)) 
								{
									
									cout << "Type Error"<< endl;
								}
								else 
								{		
									
									$$ = new Expression();		
									updateNextInstr();
									$$->type = "bool";
									updateNextInstr();
									$$->trueList = makelist(nextInstr());
									updateNextInstr();
									$$->falseList = makelist(nextInstr()+1);
									updateNextInstr();
									emit("<=", "", $1->loc->name, $3->loc->name);
									updateNextInstr();
									
									emit("goto", "");
									updateNextInstr();
									
								}		
							}  
                        | relational_expression GREATER_THAN_EQUAL_TO additive_expression
							{
								if(!compareSymbolType($1->loc, $3->loc))
								{
									
									cout << "Type Error"<< endl;
								}
								else 
								{
									
									$$ = new Expression();
									updateNextInstr();
									$$->type = "bool";
									updateNextInstr();
									$$->trueList = makelist(nextInstr());
									updateNextInstr();
									$$->falseList = makelist(nextInstr()+1);
									updateNextInstr();
									emit(">=", "", $1->loc->name, $3->loc->name);
									updateNextInstr();
									
									emit("goto", "");
									updateNextInstr();
									
								}
							}
                        ;

equality_expression: relational_expression      /* these are left associative */ 
                        {
                                $$ = $1;
                        }
                    | equality_expression EQUAL_TO relational_expression     
                    {
						if(!compareSymbolType($1->loc, $3->loc))                

						{
							
							cout << "Type Error"<< endl;
						}
						else 
						{
							
							convertBool2Int($1);                  

							updateNextInstr();	
							convertBool2Int($3);
							updateNextInstr();
							$$ = new Expression();
							updateNextInstr();
							$$->type = "bool";
							updateNextInstr();
							$$->trueList = makelist(nextInstr());            

							updateNextInstr();
							$$->falseList = makelist(nextInstr()+1); 
							updateNextInstr();
							emit("==", "", $1->loc->name, $3->loc->name);      

							updateNextInstr();
							emit("goto", "");				

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
							$$ = new Expression();                 

							updateNextInstr();
							$$->type = "bool";
							updateNextInstr();
							$$->trueList = makelist(nextInstr());
							updateNextInstr();
							$$->falseList = makelist(nextInstr()+1);
							updateNextInstr();
							emit("!=", "", $1->loc->name, $3->loc->name);
							updateNextInstr();
							
							emit("goto", "");
							updateNextInstr();
							
						}
					}        
                    ;       

logical_AND_expression: equality_expression  { $$=$1; }	   /* these are left associative */       
                        | logical_AND_expression N LOGICAL_AND M equality_expression       
                        { 
		 
							convertInt2Bool($5);         

							updateNextInstr();
							backpatch($2->nextList, nextInstr());        

							updateNextInstr();
							convertInt2Bool($1);                  

							updateNextInstr();
							$$ = new Expression();     

							updateNextInstr();
							$$->type = "bool";
							updateNextInstr();
							backpatch($1->trueList, $4);        

							updateNextInstr();
							$$->trueList = $5->trueList;        

							updateNextInstr();
							$$->falseList = merge($1->falseList, $5->falseList);    

							updateNextInstr();
							
						}    
                        ;   

logical_OR_expression: logical_AND_expression   /* these are left associative */   
                        {
                                $$ = $1;
                        }
                        | logical_OR_expression N LOGICAL_OR M logical_AND_expression     
                        { 
							
							convertInt2Bool($5);			 

							updateNextInstr();
							backpatch($2->nextList, nextInstr());	

							updateNextInstr();
							convertInt2Bool($1);			

							updateNextInstr();
							$$ = new Expression();			

							updateNextInstr();
							$$->type = "bool";
							updateNextInstr();
							backpatch($1->falseList, $4);		

							updateNextInstr();
							$$->trueList = merge($1->trueList, $5->trueList);		

							updateNextInstr();
							$$->falseList = $5->falseList;		 	

							updateNextInstr();
							
						}
                        ;

conditional_expression: logical_OR_expression   /* these are right associative */      
                        {
                                $$ = $1;
                        }
                        | logical_OR_expression N QUESTION M expression N COLON M conditional_expression    
                        {
							
							$$->loc = gentemp($5->loc->type);       

							updateNextInstr();
							$$->loc->update($5->loc->type);
							updateNextInstr();
							emit("=", $$->loc->name, $9->loc->name);      

							updateNextInstr();
							
							list<int> l = makelist(nextInstr());        

							emit("goto", "");              

							updateNextInstr();
							
							backpatch($6->nextList, nextInstr());        

							updateNextInstr();
							emit("=", $$->loc->name, $5->loc->name);
							updateNextInstr();
							
							list<int> m = makelist(nextInstr());         

							updateNextInstr();
							l = merge(l, m);						

							updateNextInstr();
							emit("goto", "");						

							updateNextInstr();
							
							backpatch($2->nextList, nextInstr());   

							updateNextInstr();
							convertInt2Bool($1);                   

							updateNextInstr();
							backpatch($1->trueList, $4);           

							updateNextInstr();
							backpatch($1->falseList, $8);          

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
								if($1->aType=="arr")       

								{
									
									$3->loc = convertType($3->loc, $1->aType);
									updateNextInstr();
									emit("[]=", $1->Array->name, $1->loc->name, $3->loc->name);		
									updateNextInstr();
									
								}
								else if($1->aType=="ptr")     
								{
									
									emit("*=", $1->Array->name, $3->loc->name);		
									updateNextInstr();
									
								}
								else                              

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
				| expression COMMA assignment_expression {   }
            ;

/* ===================================== 2. Declarations =====================================*/

declaration: type_specifier init_declarator_list SEMICOLON	{ }
			| type_specifier SEMICOLON   {       }
            ;
init_declarator_list: init_declarator	{   }
				| init_declarator_list COMMA init_declarator {   }
				;

init_declarator: declarator {$$=$1;}
                | declarator ASSIGN initializer 
                {
					if($3->val!="") $1->val=$3->val;        

					emit("=", $1->name, $3->name);
					updateNextInstr();
					
				}
                ;

type_specifier: VOID    {var_type="void";}
                | CHAR  { var_type="char"; }
                | INT   { var_type="int"; }
                ;

declarator: pointer direct_declarator 
			{
				
				symbolType *t = $1;
				updateNextInstr();
				while(t->arrtype!=NULL) t = t->arrtype;           

				updateNextInstr();
				t->arrtype = $2->type;                

				updateNextInstr();
				$$ = $2->update($1);                  

				updateNextInstr();
				
			}
        	| direct_declarator { }
            ;

direct_declarator: IDENTIFIER       
					{
						
						$$ = $1->update(new symbolType(var_type));
						updateNextInstr();
						currentSymbol = $$;
						updateNextInstr();
						
						
					}
					| direct_declarator L_SQUARE_BRACKET assignment_expression R_SQUARE_BRACKET 
					{
						
						symbolType *t = $1 -> type;
						updateNextInstr();
						symbolType *prev = NULL;
						updateNextInstr();
						while(t->type == "arr") 
						{
							prev = t;	
							t = t->arrtype;      

							updateNextInstr();
						}
						if(prev==NULL) 
						{
							
							int temp = atoi($3->loc->val.c_str());      

							updateNextInstr();
							symbolType* s = new symbolType("arr", $1->type, temp);        

							updateNextInstr();
							$$ = $1->update(s);   

							updateNextInstr();
							
						}
						else 
						{
							
							prev->arrtype =  new symbolType("arr", t, atoi($3->loc->val.c_str()));     

							updateNextInstr();
							$$ = $1->update($1->type);
							updateNextInstr();
							
						}
					}
					| direct_declarator L_SQUARE_BRACKET R_SQUARE_BRACKET 
					{
						
						symbolType *t = $1 -> type;
						updateNextInstr();
						symbolType *prev = NULL;
						updateNextInstr();
						while(t->type == "arr") 
						{
							prev = t;	
							t = t->arrtype;         

							updateNextInstr();
						}
						if(prev==NULL) 
						{
							
							symbolType* s = new symbolType("arr", $1->type, 0);    

							updateNextInstr();
							$$ = $1->update(s);
							updateNextInstr();
								
						}
						else 
						{
							
							prev->arrtype =  new symbolType("arr", t, 0);
							updateNextInstr();
							$$ = $1->update($1->type);
							updateNextInstr();
							
						}
					}
                    | direct_declarator L_SQUARE_BRACKET ASTERISK R_SQUARE_BRACKET {	}
					| direct_declarator L_ROUND_BRACKET changetable parameter_list_opt R_ROUND_BRACKET  
					{
						ST->name = $1->name;
						updateNextInstr();
						if($1->type->type !="void") 
						{
							sym *s = ST->lookup("return");         

							s->update($1->type);
							updateNextInstr();
							
						}
						$1->nested=ST;       
						updateNextInstr();	
						ST->parent = globalST;
						updateNextInstr();
						changeTable(globalST);				

						updateNextInstr();
						currentSymbol = $$;
						updateNextInstr();
						
					}
					| L_ROUND_BRACKET declarator R_ROUND_BRACKET { $$ = $2; }
                    ;

changetable: %empty 
			{ 														

				if(currentSymbol->nested==NULL) 
				{
					
					changeTable(new symTable(""));	

					updateNextInstr();
				}
				else 
				{
					
					changeTable(currentSymbol->nested);						

					updateNextInstr();
					emit("label", ST->name);
					updateNextInstr();
					
				}
			}
			;

pointer: ASTERISK   
	{ 
		$$ = new symbolType("ptr");
		updateNextInstr();
		  
	}
	| pointer ASTERISK
	{
		$$ = new symbolType("ptr", $1);
		updateNextInstr();
	}
	| %empty	{	}
        ;

parameter_list: parameter_declaration           {       }
                | parameter_list COMMA parameter_declaration {  }
                ;


parameter_list_opt: parameter_list          {	}
                    | %empty               {	}
                    ;

identifier_opt: IDENTIFIER  {	}
                | %empty   {	}
                ;

parameter_declaration: type_specifier pointer identifier_opt   {	}
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
					$$=new Statement();              

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

compound_statement: L_CURLY_BRACKET block_item_list_opt R_CURLY_BRACKET  
                {
                        $$ = $2;
                }
                    ;   

block_item_list_opt: block_item_list    
                {
                        $$ = $1;
                }
                    | %empty           { $$=new Statement(); } 
                    ;

block_item_list: block_item  
                {
                        $$ = $1;
                }  
                | block_item_list M block_item   
					{ 
						$$=$3;
						backpatch($1->nextList,$2);     

					}
                ;

block_item: declaration  { $$=new Statement(); }
            | statement  
                {
                        $$ = $1;
                }
            ;

expression_statement: expression SEMICOLON  { $$=$1;}
					| SEMICOLON { $$=new Expression(); }
                    ;

selection_statement: IF L_ROUND_BRACKET expression N R_ROUND_BRACKET M statement N 
						{
							backpatch($4->nextList, nextInstr());        

							updateNextInstr();
							convertInt2Bool($3);         

							updateNextInstr();
							$$ = new Statement();        

							updateNextInstr();
							backpatch($3->trueList, $6);        

							updateNextInstr();
							list<int> temp = merge($3->falseList, $7->nextList);   

							updateNextInstr();
							$$->nextList = merge($8->nextList, temp);
							updateNextInstr();
						}
                    | IF L_ROUND_BRACKET expression N R_ROUND_BRACKET M statement N ELSE M statement  
						{
							backpatch($4->nextList, nextInstr());		

							updateNextInstr();
							convertInt2Bool($3);        

							updateNextInstr();
							$$ = new Statement();       

							updateNextInstr();
							backpatch($3->trueList, $6);    

							updateNextInstr();
							backpatch($3->falseList, $10);
							updateNextInstr();
							list<int> temp = merge($7->nextList, $8->nextList);       

							updateNextInstr();
							$$->nextList = merge($11->nextList,temp);	
							updateNextInstr();
						}
                    ;

iteration_statement: FOR L_ROUND_BRACKET expression_statement M expression_statement M expression N R_ROUND_BRACKET M statement 
					{
						
						$$ = new Statement();		 

						updateNextInstr();
						convertInt2Bool($5);  

						updateNextInstr();
						backpatch($5->trueList, $10);	

						updateNextInstr();
						backpatch($8->nextList, $4);	

						updateNextInstr();
						backpatch($11->nextList, $6);	

						updateNextInstr();
						string str=convertToString($6);
						updateNextInstr();
						emit("goto", str);				

						updateNextInstr();
						
						$$->nextList = $5->falseList;	

						updateNextInstr();
							
					}
                    ;

jump_statement: RETURN expression SEMICOLON
				{
					$$ = new Statement();
					updateNextInstr();
					emit("return",$2->loc->name);  
					updateNextInstr();
				}
				| RETURN SEMICOLON
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


function_definition: type_specifier declarator declaration_list_opt changetable compound_statement  
					{
						
						int nextInstr=0;	 
						updateNextInstr();
						ST->parent=globalST;
						updateNextInstr();
						changeTable(globalST);                    
						updateNextInstr();
						
					}
					;

declaration_list: declaration   {  }
				| declaration_list declaration	{  }
				;				   										  				   

declaration_list_opt: %empty {  }
					| declaration_list   {  }
					;

%%

void yyerror(const char * s) {        

    cout<<s<<endl;
}
