/* test file from slide 06.14 */
%{
#include <string>
#include <stdio.h>
#include "1_A5_translator.h"
#include <iostream>              
#include <cstdlib>
#include <sstream>

extern string var_type;
extern int yylex();
void yyerror(const char *s);
vector <string> storeString;

using namespace std;
%}

%define parse.error verbose
/* ==================================== UNION =============================================== */

%union {
        char* char_value;
        int intval;
        int instrNum;

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

%token VOID CHAR INT IF ELSE FOR RETURN GOTO
%token L_SQUARE_BRACKET R_SQUARE_BRACKET L_ROUND_BRACKET R_ROUND_BRACKET L_CURLY_BRACKET R_CURLY_BRACKET 
%token ARROW AMPERSAND ASTERISK PLUS MINUS DIVIDE MODULO NOT QUESTION 
%token LESS_THAN GREATER_THAN LESS_THAN_EQUAL_TO GREATER_THAN_EQUAL_TO EQUAL_TO NOT_EQUAL_TO 
%token LOGICAL_AND LOGICAL_OR ASSIGN COLON SEMICOLON COMMA INVALID_TOKEN

%start translation_unit;

/* ==================================== Type stuff  =============================================== */
%type <unaryOp> unary_operator
%type <intval> argument_expression_list
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
        Statement 
		labeled_statement		//adding this for the labels - A4 didn't have this but this seems to me needed - source? saw something like somewhere but i don't remember where
		compound_statement
        selection_statement 
        iteration_statement 
        jump_statement  
        block_item 
        block_item_list 
        block_item_list_opt

%type <symType> pointer
%type <symPtr> initializer constant
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

N: %empty 
	{ 
        $$ = new Statement();
        $$ -> nextList = makelist(nextInstr());
        emit("GOTO", "");   
	};

/* ===================================== 1. Expressions =====================================*/
constant: INTEGER_CONSTANT 
		{
			stringstream strStr;
			strStr << $1;
			string tempStr = strStr.str();
			char* intStr = (char*)tempStr.c_str();
			string str = string(intStr);
			$$ = gentemp(new symbolType("int"), str);
			emit("ASSIGN", $$->name, $1);
			
		}
		| CHARACTER_CONSTANT 
		{
			
			$$ = gentemp(new symbolType("char"), $1);
			emit("ASSIGNCHAR", $$->name, $1);
			
		}
		;
primary_expression : IDENTIFIER 
                        {
							$$ = new Expression();
							
							$$ -> loc = $1;
							
							$$->type = "not-boolean";
							
                        }
                    | constant 
					{
						$$ = new Expression();
						$$-> loc = $1;
					}
                    | STRING_LITERAL    
                    {
                        $$=new Expression();
                        
                        $$->loc=gentemp(new symbolType("ptr"),$1);
                        
                        $$->loc->type->ptr=new symbolType("char");
						storeString.push_back($1);
						stringstream strStr;
						strStr << storeString.size()-1;
						string tempStr = strStr.str();
						char* intStr = (char*)tempStr.c_str();
						string str = string(intStr);
						emit("ASSIGNSTR", $$->loc->name, str);
                        
                        
                    }
                    | L_ROUND_BRACKET expression R_ROUND_BRACKET
                        {
                                $$ = $2;
                        }
                    ;

postfix_expression: primary_expression
                        {
                                $$=new Array();
                                
                                $$->Array=$1->loc;	
                                
                                $$->type=$1->loc->type;	
                                
                                $$->loc=$$->Array;
                                
                        }

                    | postfix_expression L_SQUARE_BRACKET expression R_SQUARE_BRACKET
                	{ 	
                                	 
						$$=new Array();						
						$$->Array = $1->loc;
						$$->type = $1->type->ptr;
						$$->loc = gentemp(new symbolType("int"));

						if ($1->aType == "arr")
						{
							sym*t = gentemp(new symbolType("int"));
							stringstream strStr;
							strStr << sizeOfType($$->type);
							string tempStr = strStr.str();
							char* intStr = (char*)tempStr.c_str();
							string str = string(intStr);
							emit("ASTERISK", t->name, $3->loc->name, str);
							emit("PLUS", $$->loc->name, $1->loc->name, t->name);
						}
						else
						{
							stringstream strStr;
							strStr << sizeOfType($$->type);
							string tempStr = strStr.str();
							char* intStr1 = (char*)tempStr.c_str();
							string str1 = string(intStr1);
							emit("*", $$->loc->name, $3->loc->name, str1);
						}
					$$->aType = "arr";
	        }
                    | postfix_expression L_ROUND_BRACKET argument_expression_list R_ROUND_BRACKET
                    {
                        $$=new Array();	
                        
                        $$->Array=gentemp($1->type);
						stringstream strStr;
						strStr << $3;
						string tempStr = strStr.str();
						char* intStr = (char*)tempStr.c_str();
						string str = string(intStr);
						emit("call", $$->Array->name, $1->Array->name, str);
                        
                    }
                    | postfix_expression ARROW IDENTIFIER {  }/* pointer indirection only one level */
                    ;

argument_expression_list: assignment_expression
                        {
                                $$ = 1;
                                
                                emit("param",$1->loc->name);	
                                
                        }
                        | argument_expression_list COMMA assignment_expression
                        {
                                $$ = $1+1;
                                
                                emit("param",$3->loc->name);	
                                
                        }
                        ;

unary_expression: postfix_expression { $$=$1; } 	
                | unary_operator unary_expression
                {			

                        $$=new Array();
                        
                        switch($1)
                                {	  
                                        case '+':  
                                                $$=$2;
                                                break;          
                                        case '-':				
                                                $$->Array=gentemp(new symbolType($2->Array->type->type));
                                                
                                                emit("UMINUS",$$->Array->name,$2->Array->name);
                                                
                                                break; 

                                        case '!':			
                                                $$->Array=gentemp(new symbolType($2->Array->type->type));
                                                
                                                emit("!",$$->Array->name,$2->Array->name);
                                                
                                                break;

										default:
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

multiplicative_expression: unary_expression    
                           {
		 
								$$ = new Expression();             
														    
								if($1->aType=="arr") 			  
								{
									$$->loc = gentemp($1->loc->type);	
									
									emit("=[]", $$->loc->name, $1->Array->name, $1->loc->name);     

									
									
								}
								else if($1->aType=="ptr")         

								{ 
									$$->loc = $1->loc;        

									
									
								}
								else
								{
									$$->loc = $1->Array;
									
									
								}
							}

                            | multiplicative_expression ASTERISK unary_expression   
                            	{ 
			
									if(!compareSymbolType($1->loc, $3->Array))         
										cout<<"Type Error"<< endl;	
									else 								 
									{
										$$ = new Expression();	
										
										$$->loc = gentemp(new symbolType($1->loc->type->type));
										
										emit("ASTERISK", $$->loc->name, $1->loc->name, $3->Array->name);
										
										
									}
								}
                            | multiplicative_expression DIVIDE unary_expression     
                            	{
									
									if(!compareSymbolType($1->loc, $3->Array))
										cout << "Type Error"<< endl;
									else    
									{
										$$ = new Expression();
										
										$$->loc = gentemp(new symbolType($1->loc->type->type));
										
										emit("DIVIDE", $$->loc->name, $1->loc->name, $3->Array->name);
											
																
									}
								}
                            | multiplicative_expression MODULO unary_expression     
                            	{
		 
									if(!compareSymbolType($1->loc, $3->Array))
										cout << "Type Error"<< endl;		
									else 		
									{
										$$ = new Expression();
										
										$$->loc = gentemp(new symbolType($1->loc->type->type));
										
										emit("MODULO", $$->loc->name, $1->loc->name, $3->Array->name);	
											
											
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
								
								$$->loc = gentemp(new symbolType($1->loc->type->type));
								
								emit("PLUS", $$->loc->name, $1->loc->name, $3->loc->name);
								
								
							}
						}             
                    | additive_expression MINUS multiplicative_expression      
                    	{
		 
							if(!compareSymbolType($1->loc, $3->loc))
								cout << "Type Error"<< endl;		
							else       
							{	
								$$ = new Expression();	
								
								$$->loc = gentemp(new symbolType($1->loc->type->type));
								
								emit("MINUS", $$->loc->name, $1->loc->name, $3->loc->name);
								
								
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
									
									cout << "Type Error"<< endl;
								}
								else 
								{      

																
									$$ = new Expression();
									
									$$->type = "bool";                         

											
									$$->trueList = makelist(nextInstr());     

									
									$$->falseList = makelist(nextInstr()+1);
									
									emit("LESS_THAN", "", $1->loc->name, $3->loc->name);     

									
									
									emit("GOTO", "");	

									
									
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
									
									$$->type = "bool";
									
									$$->trueList = makelist(nextInstr());
									
									$$->falseList = makelist(nextInstr()+1);
									
									emit("GREATER_THAN", "", $1->loc->name, $3->loc->name);
									
									
									emit("GOTO", "");
									
									
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
									
									$$->type = "bool";
									
									$$->trueList = makelist(nextInstr());
									
									$$->falseList = makelist(nextInstr()+1);
									
									emit("<=", "", $1->loc->name, $3->loc->name);
									
									
									emit("GOTO", "");
									
									
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
									
									$$->type = "bool";
									
									$$->trueList = makelist(nextInstr());
									
									$$->falseList = makelist(nextInstr()+1);
									
									emit("GREATER_THAN_EQUAL_TO", "", $1->loc->name, $3->loc->name);
									
									
									emit("GOTO", "");
									
									
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

								
							convertBool2Int($3);
							
							$$ = new Expression();
							
							$$->type = "bool";
							
							$$->trueList = makelist(nextInstr());            

							
							$$->falseList = makelist(nextInstr()+1); 
							
							emit("EQUAL_TO", "", $1->loc->name, $3->loc->name);      

							
							emit("GOTO", "");				

							
							
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
							
							convertBool2Int($3);
							
							$$ = new Expression();                 

							
							$$->type = "bool";
							
							$$->trueList = makelist(nextInstr());
							
							$$->falseList = makelist(nextInstr()+1);
							
							emit("NOT_EQUAL_TO", "", $1->loc->name, $3->loc->name);
							
							
							emit("GOTO", "");
							
							
						}
					}        
                    ;       

logical_AND_expression: equality_expression  { $$=$1; }	   /* these are left associative */       
                        | logical_AND_expression N LOGICAL_AND M equality_expression       
                        { 
		 
							convertInt2Bool($5);         

							
							backpatch($2->nextList, nextInstr());        

							
							convertInt2Bool($1);                  

							
							$$ = new Expression();     

							
							$$->type = "bool";
							
							backpatch($1->trueList, $4);        

							
							$$->trueList = $5->trueList;        

							
							$$->falseList = merge($1->falseList, $5->falseList);    

							
							
						}    
                        ;   

logical_OR_expression: logical_AND_expression   /* these are left associative */   
                        {
                                $$ = $1;
                        }
                        | logical_OR_expression N LOGICAL_OR M logical_AND_expression     
                        { 
							
							convertInt2Bool($5);			 

							
							backpatch($2->nextList, nextInstr());	

							
							convertInt2Bool($1);			

							
							$$ = new Expression();			

							
							$$->type = "bool";
							
							backpatch($1->falseList, $4);		

							
							$$->trueList = merge($1->trueList, $5->trueList);		

							
							$$->falseList = $5->falseList;		 	

							
							
						}
                        ;

conditional_expression: logical_OR_expression   /* these are right associative */      
                        {
                                $$ = $1;
                        }
                        | logical_OR_expression N QUESTION M expression N COLON M conditional_expression    
                        {
							
							$$->loc = gentemp($5->loc->type);       

							
							$$->loc->update($5->loc->type);
							
							emit("ASSIGN", $$->loc->name, $9->loc->name);      

							
							
							list<int> l = makelist(nextInstr());        

							emit("GOTO", "");              

							
							
							backpatch($6->nextList, nextInstr());        

							
							emit("ASSIGN", $$->loc->name, $5->loc->name);
							
							
							list<int> m = makelist(nextInstr());         

							
							l = merge(l, m);						

							
							emit("GOTO", "");						

							
							
							backpatch($2->nextList, nextInstr());   

							
							convertInt2Bool($1);                   

							
							backpatch($1->trueList, $4);           

							
							backpatch($1->falseList, $8);          

							
							backpatch(l, nextInstr());
							
							
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
									
									$3->loc = convertType($3->loc, $1->type->type);
									
									emit("[]=", $1->Array->name, $1->loc->name, $3->loc->name);		
									
									
								}
								else if($1->aType=="ptr")     
								{
									
									emit("*=", $1->Array->name, $3->loc->name);		
									
									
								}
								else                              

								{
									
									$3->loc = convertType($3->loc, $1->Array->type->type);
									emit("ASSIGN", $1->Array->name, $3->loc->name);
									
									
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

init_declarator_list: init_declarator { }
					| init_declarator_list COMMA init_declarator { }
					;

init_declarator: declarator {$$=$1;}
                | declarator ASSIGN initializer 
                {
					if($3->val!="") $1->val=$3->val;        

					emit("ASSIGN", $1->name, $3->name);
					
					
				}
                ;

type_specifier: VOID    {var_type="void";}
                | CHAR  { var_type="char"; }
                | INT   { var_type="int"; }

                ;

declarator: pointer direct_declarator 
			{
				symbolType * t = $1;
				while (t->ptr !=NULL) t = t->ptr;
				t->ptr = $2->type;
				$$ = $2->update($1);
			}
        	| direct_declarator { }
            ;

direct_declarator: IDENTIFIER       
					{
						
						$$ = $1->update(new symbolType(var_type));
						
						currentSymbol = $$;
						
					}
					| direct_declarator L_SQUARE_BRACKET assignment_expression R_SQUARE_BRACKET 
					{
						
						symbolType *t = $1 -> type;
						
						symbolType *prev = NULL;
						
						while(t->type == "arr") 
						{
							prev = t;	
							t = t->ptr;      

							
						}
						if(prev==NULL) 
						{
							
							int temp = atoi($3->loc->val.c_str());      
							symbolType* s = new symbolType("arr", $1->type, temp);        
							$$ = $1->update(s);   

							
							
						}
						else 
						{
							
							prev->ptr =  new symbolType("arr", t, atoi($3->loc->val.c_str()));     							
							$$ = $1->update($1->type);
							
							
						}
					}
					| direct_declarator L_SQUARE_BRACKET R_SQUARE_BRACKET 
					{
						
						symbolType *t = $1 -> type;
						
						symbolType *prev = NULL;
						
						while(t->type == "arr") 
						{
							prev = t;	
							t = t->ptr;         

							
						}
						if(prev==NULL) 
						{
							
							symbolType* s = new symbolType("arr", $1->type, 0);    

							
							$$ = $1->update(s);
							
								
						}
						else 
						{
							
							prev->ptr =  new symbolType("arr", t, 0);
							
							$$ = $1->update($1->type);
							
							
						}
					}
					| direct_declarator L_ROUND_BRACKET changetable parameter_list_opt R_ROUND_BRACKET  
					{
						table->name = $1->name;
						
						if($1->type->type !="void") 
						{
							sym *s = table->lookup("RETURN");         

							s->update($1->type);
							
							
						}
						$1->nested=table;       
							
						table->parent = globalST;
						$1->category = "function";
						
						changeTable(globalST);				

						
						currentSymbol = $$;
						
						
					}
					| L_ROUND_BRACKET declarator R_ROUND_BRACKET { $$ = $2; }
                    ;

changetable: %empty 
			{ 														

				if(currentSymbol->nested==NULL) 
				{
					
					changeTable(new symTable(""));	
					
				}
				else 
				{
					
					changeTable(currentSymbol->nested);						
					
					emit("FUNC", table->name);
					
					
				}
			}
			;

pointer: ASTERISK   
	{ 
		$$ = new symbolType("ptr");
		
		  
	}
	| ASTERISK pointer
	{
		$$ = new symbolType("ptr", $2);
		
	}
        ;

parameter_list: parameter_declaration           {       }
                | parameter_list COMMA parameter_declaration {  }
                ;

parameter_list_opt: parameter_list          {	}
                    | %empty               {	}
                    ;

parameter_declaration: type_specifier declarator   { $2->category = "param";} 
						| type_specifier { }
                         ;

initializer: assignment_expression   { $$=$1->loc; }  
			| L_CURLY_BRACKET initializer R_CURLY_BRACKET { }
			| L_CURLY_BRACKET initializer COMMA R_CURLY_BRACKET { }
            ;

/* ===================================== 3. Statements =====================================*/

Statement: labeled_statement { }
			| compound_statement 
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

labeled_statement: IDENTIFIER COLON Statement  
				{
						$$ = $3;
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
            | Statement  
                {
                        $$ = $1;
                }
            ;

expression_statement: expression SEMICOLON  { $$=$1;}
					| SEMICOLON { $$=new Expression(); }
                    ;

selection_statement: IF L_ROUND_BRACKET expression N R_ROUND_BRACKET M Statement N 
						{
							backpatch($4->nextList, nextInstr());        

							
							convertInt2Bool($3);         

							
							$$ = new Statement();        

							
							backpatch($3->trueList, $6);        

							
							list<int> temp = merge($3->falseList, $7->nextList);   

							
							$$->nextList = merge($8->nextList, temp);
							
						}
                    | IF L_ROUND_BRACKET expression N R_ROUND_BRACKET M Statement N ELSE M Statement  
						{
							backpatch($4->nextList, nextInstr());		

							
							convertInt2Bool($3);        

							
							$$ = new Statement();       

							
							backpatch($3->trueList, $6);    

							
							backpatch($3->falseList, $10);
							
							list<int> temp = merge($7->nextList, $8->nextList);       

							
							$$->nextList = merge($11->nextList,temp);	
							
						}
                    ;

iteration_statement: FOR L_ROUND_BRACKET expression_statement M expression_statement M expression N R_ROUND_BRACKET M Statement 
					{
						
						$$ = new Statement();		 

						
						convertInt2Bool($5);  

						
						backpatch($5->trueList, $10);	

						
						backpatch($8->nextList, $4);	

						
						backpatch($11->nextList, $6);	

						
						
						stringstream strStr;
						strStr << $6;
						string tempStr = strStr.str();
						char* intStr = (char*) tempStr.c_str();
						string str = string(intStr);
						
						emit("GOTO", str);							
						$$->nextList = $5->falseList;	
					}
                    ;

jump_statement: RETURN expression SEMICOLON
				{
					$$ = new Statement();
					
					emit("RETURN",$2->loc->name);  
					
				}
				| RETURN SEMICOLON
				{
					$$ = new Statement();
					
					emit("RETURN", "");
					
				}
                ;

/* ===================================== 4. Translation Unit =====================================*/


translation_unit: external_declaration                  {   }
                | translation_unit external_declaration  {   }
                ;

external_declaration: function_definition       {   }
                    | declaration         {   }
                    ;

function_definition: type_specifier declarator declaration_list changetable compound_statement  {}
					|type_specifier declarator changetable compound_statement
					{
						
						emit("FUNCEND", table->name);
						table->parent=globalST;
						changeTable(globalST);                    
						
						
					}
					;

declaration_list: declaration   {  }
				| declaration_list declaration	{  }
				;				   										  				   
%%

void yyerror(const char * s) {        
		cout << "Error (this one is generated using yyeror func): " << s << endl;
}
