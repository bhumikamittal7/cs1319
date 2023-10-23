/* test file from slide 06.14 */

%{ 
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
extern int yylex();

void yyerror(const char *);

%}

%define parse.error verbose

%token VOID CHAR INT IF ELSE FOR RETURN 
%token IDENTIFIER INTEGER_CONSTANT CHARACTER_CONSTANT STRING_LITERAL 
%token L_SQUARE_BRACKET R_SQUARE_BRACKET L_ROUND_BRACKET R_ROUND_BRACKET L_CURLY_BRACKET R_CURLY_BRACKET 
%token ARROW AMPERSAND ASTERISK PLUS MINUS DIVIDE MODULO NOT QUESTION 
%token LESS_THAN GREATER_THAN LESS_THAN_EQUAL_TO GREATER_THAN_EQUAL_TO EQUAL_TO NOT_EQUAL_TO 
%token LOGICAL_AND LOGICAL_OR ASSIGN COLON SEMICOLON COMMA INVALID_TOKEN

%start translation_unit

%%

/* 1. Expressions */

primary_expression : IDENTIFIER { printf("primary_expression\n"); }
                    | INTEGER_CONSTANT  { printf("primary_expression\n"); }
                    | CHARACTER_CONSTANT    { printf("primary_expression\n"); }
                    | STRING_LITERAL    { printf("primary_expression\n"); }
                    | L_ROUND_BRACKET expression R_ROUND_BRACKET    { printf("primary_expression\n"); }
                    ;

argument_expression_list_opt: argument_expression_list  { printf("argument_expression_list_opt\n");}
                            | %empty    { printf("argument_expression_list_opt\n"); }
                            ;

postfix_expression: primary_expression  { printf("postfix_expression\n"); }
                    | postfix_expression L_SQUARE_BRACKET expression R_SQUARE_BRACKET   { printf("postfix_expression\n");}
                    | postfix_expression L_ROUND_BRACKET argument_expression_list_opt R_ROUND_BRACKET   { printf("postfix_expression\n");}
                    | postfix_expression ARROW IDENTIFIER /* pointer indirection only one level */  { printf("postfix_expression\n");}
                    ;

argument_expression_list: assignment_expression { printf("argument_expression_list\n"); }
                        | argument_expression_list COMMA assignment_expression  { printf("argument_expression_list\n"); }
                        ;

unary_expression: postfix_expression    { printf("unary_expression\n");}
                | unary_operator unary_expression   /* this is done to make it non associative, use unary_operator unary_expression */ { printf("unary_expression\n");}
                /* only a single prefix op is allowed - check here again */
                ;

unary_operator: AMPERSAND { printf("unary_operator\n");}
                | ASTERISK  { printf("unary_operator\n");}
                | PLUS  { printf("unary_operator\n");}
                | MINUS     { printf("unary_operator\n");}
                | NOT   { printf("unary_operator\n");}
                ;

multiplicative_expression: unary_expression     /* these are left associative */    { printf("multiplicative_expression\n");}
                            | multiplicative_expression ASTERISK unary_expression   { printf("multiplicative_expression\n");}
                            | multiplicative_expression DIVIDE unary_expression     { printf("multiplicative_expression\n");}
                            | multiplicative_expression MODULO unary_expression     { printf("multiplicative_expression\n");}
                            ;

additive_expression: multiplicative_expression  /* these are left associative */        { printf("additive_expression\n");}
                    | additive_expression PLUS multiplicative_expression                { printf("additive_expression\n");}
                    | additive_expression MINUS multiplicative_expression               { printf("additive_expression\n");}
                    ;

relational_expression: additive_expression      /* these are left associative */        { printf("relational_expression\n");}
                        | relational_expression LESS_THAN additive_expression           { printf("relational_expression\n");}
                        | relational_expression GREATER_THAN additive_expression           { printf("relational_expression\n");}
                        | relational_expression LESS_THAN_EQUAL_TO additive_expression      { printf("relational_expression\n");}
                        | relational_expression GREATER_THAN_EQUAL_TO additive_expression   { printf("relational_expression\n");}
                        ;

equality_expression: relational_expression      /* these are left associative */        { printf("equality_expression\n");}
                    | equality_expression EQUAL_TO relational_expression                { printf("equality_expression\n");}
                    | equality_expression NOT_EQUAL_TO relational_expression            { printf("equality_expression\n");}
                    ;       

logical_AND_expression: equality_expression     /* these are left associative */        { printf("logical_AND_expression\n");}
                        | logical_AND_expression LOGICAL_AND equality_expression        { printf("logical_AND_expression\n");}
                        ;   

logical_OR_expression: logical_AND_expression   /* these are left associative */        { printf("logical_OR_expression\n");}
                        | logical_OR_expression LOGICAL_OR logical_AND_expression       { printf("logical_OR_expression\n");}
                        ;

conditional_expression: logical_OR_expression   /* these are right associative */       { printf("conditional_expression\n");}
                        | logical_OR_expression QUESTION expression COLON conditional_expression    { printf("conditional_expression\n");}
                        ;

assignment_expression: conditional_expression   /* these are right associative */       { printf("assignment_expression\n");}
                        | unary_expression ASSIGN assignment_expression                 { printf("assignment_expression\n");}
                        ;

expression: assignment_expression           { printf("expression\n");}
            ;

/* 2. Declaration */    

declaration: type_specifier init_declarator SEMICOLON   { printf("declaration\n");}
            ;

init_declarator: declarator { printf("init_declarator\n");}
                | declarator ASSIGN initializer { printf("init_declarator\n");}
                ;

type_specifier: VOID    { printf("type_specifier\n");}
                | CHAR  { printf("type_specifier\n");}
                | INT   { printf("type_specifier\n");}
                ;

pointer_opt: pointer    { printf("pointer_opt\n");}
            | %empty    { printf("pointer_opt\n"); }
            ;

declarator: pointer_opt direct_declarator   { printf("declarator\n"); }
            ;

parameter_list_opt: parameter_list          { printf("parameter_list_opt\n"); }
                    | %empty                { printf("parameter_list_opt\n"); }
                    ;

direct_declarator: IDENTIFIER         { printf("direct_declarator\n"); }
                    | IDENTIFIER L_SQUARE_BRACKET INTEGER_CONSTANT R_SQUARE_BRACKET   /* check here again */    { printf("direct_declarator\n"); }
                    | IDENTIFIER L_ROUND_BRACKET parameter_list_opt R_ROUND_BRACKET     { printf("direct_declarator\n"); }
                    ;

pointer: ASTERISK   { printf("pointer\n"); }
        ;

parameter_list: parameter_declaration   { printf("parameter_list\n"); }
                | parameter_list COMMA parameter_declaration    { printf("parameter_list\n"); }
                ;

identifier_opt: IDENTIFIER  { printf("identifier_opt\n"); }
                | %empty    { printf("identifier_opt\n"); }
                ;

parameter_declaration: type_specifier pointer_opt identifier_opt    { printf("parameter_declaration\n"); }
                        ;

initializer: assignment_expression  { printf("initializer\n"); }
            ;

/* 3. Statements */

statement: compound_statement   { printf("statement\n");}
            | expression_statement  { printf("statement\n");}
            | selection_statement   { printf("statement\n");}
            | iteration_statement   { printf("statement\n");}
            | jump_statement        { printf("statement\n");}
            ;

block_item_list_opt: block_item_list    { printf("block_item_list_opt\n");}
                    | %empty            { printf("block_item_list_opt\n"); }
                    ;

compound_statement: L_CURLY_BRACKET block_item_list_opt R_CURLY_BRACKET  { printf("compound_statement\n"); }
                    ;   

block_item_list: block_item     { printf("block_item_list\n"); }
                | block_item_list block_item    { printf("block_item_list\n"); }
                ;

block_item: declaration  { printf("block_item\n"); }
            | statement     { printf("block_item\n"); }
            ;

expression_opt: expression  { printf("expression_opt\n"); }
                | %empty    { printf("expression_opt\n"); }
                ;

expression_statement: expression_opt SEMICOLON  { printf("expression_statement\n"); }
                    ;

selection_statement: IF L_ROUND_BRACKET expression R_ROUND_BRACKET statement    { printf("selection_statement\n"); }
                    | IF L_ROUND_BRACKET expression R_ROUND_BRACKET statement ELSE statement    { printf("selection_statement\n"); }
                    ;

iteration_statement: FOR L_ROUND_BRACKET expression_opt SEMICOLON expression_opt SEMICOLON expression_opt R_ROUND_BRACKET statement   { printf("iteration_statement\n"); }
                    ;

jump_statement: RETURN expression_opt SEMICOLON   { printf("jump_statement\n"); }
                ;

/* 4. Translation Unit */

translation_unit: function_definition   { printf("translation_unit\n"); }
                | declaration        { printf("translation_unit\n"); }
                ;

function_definition: type_specifier declarator compound_statement   { printf("function_definition\n"); }
                    ;

%%

//c code

void yyerror(const char *s) {
    fprintf(stderr, "%s\n", s);
    exit(EXIT_FAILURE);
}