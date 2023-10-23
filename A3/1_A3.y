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

primary_expression : IDENTIFIER
                    | INTEGER_CONSTANT
                    | CHARACTER_CONSTANT
                    | STRING_LITERAL
                    | '(' expression ')'
                    ;

argument_expression_list_opt: argument_expression_list
                            | %empty
                            ;

postfix_expression: primary_expression
                    | postfix_expression '[' expression ']'
                    | postfix_expression '(' argument_expression_list_opt ')'
                    | postfix_expression ARROW IDENTIFIER /* pointer indirection only one level */
                    ;

argument_expression_list: assignment_expression
                        | argument_expression_list ',' assignment_expression
                        ;

unary_expression: postfix_expression
                | unary_operator unary_expression   /* this is done to make it non associative, use unary_operator unary_expression */
                /* only a single prefix op is allowed - check here again */
                ;

unary_operator: '&' | '*' | '+' | '-' | '!'
                ;

multiplicative_expression: unary_expression     /* these are left associative */
                            | multiplicative_expression '*' unary_expression
                            | multiplicative_expression '/' unary_expression
                            | multiplicative_expression '%' unary_expression
                            ;

additive_expression: multiplicative_expression  /* these are left associative */
                    | additive_expression '+' multiplicative_expression
                    | additive_expression '-' multiplicative_expression
                    ;

relational_expression: additive_expression      /* these are left associative */
                        | relational_expression '<' additive_expression
                        | relational_expression '>' additive_expression
                        | relational_expression LESS_THAN_EQUAL_TO additive_expression
                        | relational_expression GREATER_THAN_EQUAL_TO additive_expression
                        ;

equality_expression: relational_expression      /* these are left associative */
                    | equality_expression EQUAL_TO relational_expression
                    | equality_expression NOT_EQUAL_TO relational_expression
                    ;

logical_AND_expression: equality_expression     /* these are left associative */
                        | logical_AND_expression LOGICAL_AND equality_expression
                        ;

logical_OR_expression: logical_AND_expression   /* these are left associative */
                        | logical_OR_expression LOGICAL_OR logical_AND_expression
                        ;

conditional_expression: logical_OR_expression   /* these are right associative */
                        | logical_OR_expression '?' expression ':' conditional_expression
                        ;

assignment_expression: conditional_expression   /* these are right associative */
                        | unary_expression '=' assignment_expression
                        ;

expression: assignment_expression
            ;

/* 2. Declaration */

declaration: type_specifier init_declarator ';'
            ;

init_declarator: declarator
                | declarator '=' initializer
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
                    | IDENTIFIER '[' INTEGER_CONSTANT ']'   /* check here again */
                    | IDENTIFIER '(' parameter_list_opt ')'
                    ;

pointer: '*'
        ;

parameter_list: parameter_declaration
                | parameter_list ',' parameter_declaration
                ;

identifier_opt: IDENTIFIER
                | %empty
                ;

parameter_declaration: type_specifier pointer_opt identifier_opt
                        ;

initializer: assignment_expression
            ;

/* 3. Statements */

statement: compound_statement
            | expression_statement
            | selection_statement
            | iteration_statement
            | jump_statement
            ;

block_item_list_opt: block_item_list
                    | %empty
                    ;

compound_statement: '{' block_item_list_opt '}'
                    ;

block_item_list: block_item
                | block_item_list block_item
                ;

block_item: declaration
            | statement
            ;

expression_opt: expression
                | %empty
                ;

expression_statement: expression_opt ';'
                    ;

selection_statement: IF '(' expression ')' statement
                    | IF '(' expression ')' statement ELSE statement
                    ;

iteration_statement: FOR '(' expression_opt ';' expression_opt ';' expression_opt ')' statement
                    ;

jump_statement: RETURN expression_opt ';'
                ;

/* 4. Translation Unit */

translation_unit: function_definition
                | declaration
                ;

function_definition: type_specifier declarator compound_statement
                    ;

%%

//c code

void yyerror(const char *s) {
    fprintf(stderr, "%s\n", s);
    exit(EXIT_FAILURE);
}