/* test file from slide 06.14 */
%{
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "1_A4_translator.h"

extern int yylex();
void yyerror(const char *s);
%}

//detailed error messages
// %define parse.error verbose

%union {
    int intValue;
    char charValue;
    char *strValue;
    struct symTable *symPtr;
}
/* ==================================== TOKENS =============================================== */

// %token <symPtr> IDENTIFIER

// %token <intValue> INTEGER_CONSTANT
// %token <charValue> CHARACTER_CONSTANT
// %token <charValue> STRING_LITERAL

%token VOID CHAR INT IF ELSE FOR RETURN 
%token L_SQUARE_BRACKET R_SQUARE_BRACKET L_ROUND_BRACKET R_ROUND_BRACKET L_CURLY_BRACKET R_CURLY_BRACKET 
%token ARROW AMPERSAND ASTERISK PLUS MINUS DIVIDE MODULO NOT QUESTION 
%token LESS_THAN GREATER_THAN LESS_THAN_EQUAL_TO GREATER_THAN_EQUAL_TO EQUAL_TO NOT_EQUAL_TO 
%token LOGICAL_AND LOGICAL_OR ASSIGN COLON SEMICOLON COMMA INVALID_TOKEN

/* =================== Auxillary non-terminals M and N used for backpatching =================== */

/* ==================================== Type stuff  =============================================== */


/* ===================================== start of non-terminals =====================================*/

%start translation_unit;

%%

/* ===================================== 1. Expressions =====================================*/

constant: INTEGER_CONSTANT 
        | CHARACTER_CONSTANT
        ;

primary_expression : IDENTIFIER 
                    | constant 
                    | STRING_LITERAL    
                    | L_ROUND_BRACKET expression R_ROUND_BRACKET
                    ;

argument_expression_list_opt: argument_expression_list 
                            | %empty
                            ;

postfix_expression: primary_expression
                    | postfix_expression L_SQUARE_BRACKET expression R_SQUARE_BRACKET
                    | postfix_expression L_ROUND_BRACKET argument_expression_list_opt R_ROUND_BRACKET
                    | postfix_expression ARROW IDENTIFIER /* pointer indirection only one level */
                    ;

argument_expression_list: assignment_expression
                        | argument_expression_list COMMA assignment_expression
                        ;

unary_expression: postfix_expression
                | unary_operator unary_expression
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
                            | multiplicative_expression DIVIDE unary_expression     
                            | multiplicative_expression MODULO unary_expression     
                            ;

additive_expression: multiplicative_expression  /* these are left associative */    
                        {
                                $$ = $1;
                        }
                    | additive_expression PLUS multiplicative_expression                
                    | additive_expression MINUS multiplicative_expression               
                    ;

relational_expression: additive_expression      /* these are left associative */        
                        {
                                $$ = $1;
                        }
                        | relational_expression LESS_THAN additive_expression           
                        | relational_expression GREATER_THAN additive_expression        
                        | relational_expression LESS_THAN_EQUAL_TO additive_expression  
                        | relational_expression GREATER_THAN_EQUAL_TO additive_expression
                        ;

equality_expression: relational_expression      /* these are left associative */ 
                        {
                                $$ = $1;
                        }
                    | equality_expression EQUAL_TO relational_expression                
                    | equality_expression NOT_EQUAL_TO relational_expression           
                    ;       

logical_AND_expression: equality_expression     /* these are left associative */       
                        | logical_AND_expression LOGICAL_AND equality_expression       
                        ;   

logical_OR_expression: logical_AND_expression   /* these are left associative */   
                        {
                                $$ = $1;
                        }
                        | logical_OR_expression LOGICAL_OR logical_AND_expression      
                        ;

conditional_expression: logical_OR_expression   /* these are right associative */      
                        {
                                $$ = $1;
                        }
                        | logical_OR_expression QUESTION expression COLON conditional_expression    
                        ;

assignment_expression: conditional_expression   /* these are right associative */      
                        {
                                $$ = $1;
                        }
                        | unary_expression ASSIGN assignment_expression                
                        ;

expression: assignment_expression
                {
                        $$ = $1;
                }
            ;

/* ===================================== 2. Declarations =====================================*/

declaration: type_specifier init_declarator SEMICOLON   {       }
            ;

init_declarator: declarator 
                | declarator ASSIGN initializer 
                ;

type_specifier: VOID    
                | CHAR  
                | INT   
                ;

pointer_opt: pointer   
            | %empty    
            ;

declarator: pointer_opt direct_declarator 
            ;

parameter_list_opt: parameter_list          
                    | %empty               
                    ;

direct_declarator: IDENTIFIER       
                    | IDENTIFIER L_SQUARE_BRACKET INTEGER_CONSTANT R_SQUARE_BRACKET  
                    | IDENTIFIER L_ROUND_BRACKET parameter_list_opt R_ROUND_BRACKET  
                    ;

pointer: ASTERISK   
        ;

parameter_list: parameter_declaration           {       }
                | parameter_list COMMA parameter_declaration {  }
                ;

identifier_opt: IDENTIFIER  
                | %empty   
                ;

parameter_declaration: type_specifier pointer_opt identifier_opt   
                        ;

initializer: assignment_expression  
            ;

/* ===================================== 3. Statements =====================================*/

statement: compound_statement 
                {
                        $$ = $1;
                }
            | expression_statement 
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
                    | %empty           
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
                | block_item_list block_item   
                ;

block_item: declaration  
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
                        //stuff here
                }
                ;

expression_statement: expression_opt SEMICOLON  {       }
                    ;

selection_statement: IF L_ROUND_BRACKET expression R_ROUND_BRACKET statement    
                    | IF L_ROUND_BRACKET expression R_ROUND_BRACKET statement ELSE statement  
                    ;

iteration_statement: FOR L_ROUND_BRACKET expression_opt SEMICOLON expression_opt SEMICOLON expression_opt R_ROUND_BRACKET statement 
                    ;

jump_statement: RETURN expression_opt SEMICOLON  
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
                                //stuff here
                        }
                    ;

%%

