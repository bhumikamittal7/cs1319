/* test file from slide 06.14 */

%{ 
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
extern int yylex();

void yyerror(const char *);

%}

%define parse.error verbose
%token IDENTIFIER CONSTANT STRING_LITERAL PUNCTUATOR KEYWORD

%start translation-unit

%%

/* 1. Expressions */

primary-expression : IDENTIFIER
                    | CONSTANT
                    | STRING_LITERAL
                    | '(' expression ')'
                    ;

argument-expression-list-opt: argument-expression-list
                            | %empty
                            ;

postfix-expression: primary-expression
                    | postfix-expression '[' expression ']'
                    | postfix-expression '(' argument-expression-list-opt ')'
                    | postfix-expression "->" IDENTIFIER /* pointer indirection only one level */
                    ;

argument-expression-list: assignment-expression
                        | argument-expression-list ',' assignment-expression
                        ;

unary-expression: postfix-expression
                | unary-operator unary-expression   /* this is done to make it non associative, use unary-operator unary-expression */
                /* only a single prefix op is allowed - check here again */
                ;

unary-operator: '&' | '*' | '+' | '-' | '!'
                ;

multiplicative-expression: unary-expression     /* these are left associative */
                            | multiplicative-expression '*' unary-expression
                            | multiplicative-expression '/' unary-expression
                            | multiplicative-expression '%' unary-expression
                            ;

additive-expression: multiplicative-expression  /* these are left associative */
                    | additive-expression '+' multiplicative-expression
                    | additive-expression '-' multiplicative-expression
                    ;

relational-expression: additive-expression      /* these are left associative */
                        | relational-expression '<' additive-expression
                        | relational-expression '>' additive-expression
                        | relational-expression "<=" additive-expression
                        | relational-expression ">=" additive-expression
                        ;

equality-expression: relational-expression      /* these are left associative */
                    | equality-expression "==" relational-expression
                    | equality-expression "!=" relational-expression
                    ;

logical-AND-expression: equality-expression     /* these are left associative */
                        | logical-AND-expression "&&" equality-expression
                        ;

logical-OR-expression: logical-AND-expression   /* these are left associative */
                        | logical-OR-expression "||" logical-AND-expression
                        ;

conditional-expression: logical-OR-expression   /* these are right associative */
                        | logical-OR-expression '?' expression ':' conditional-expression
                        ;

assignment-expression: conditional-expression   /* these are right associative */
                        | unary-expression '=' assignment-expression
                        ;

expression: assignment-expression
            ;

/* 2. Declaration */

declaration: type-specifier init-declarator ';'
            ;

init-declarator: declarator
                | declarator '=' initializer
                ;

type-specifier: "void"
                | "char"
                | "int"
                ;

pointer-opt: pointer
            | %empty
            ;

declarator: pointer-opt direct-declarator
            ;

parameter-list-opt: parameter-list
                    | %empty
                    ;

direct-declarator: IDENTIFIER
                    | IDENTIFIER '[' CONSTANT ']'   /* check here again */
                    | IDENTIFIER '(' parameter-list-opt ')'
                    ;

pointer: '*'

parameter-list: parameter-declaration
                | parameter-list ',' parameter-declaration
                ;

identifier-opt: IDENTIFIER
                | %empty
                ;

parameter-declaration: type-specifier pointer-opt identifier-opt
                        ;

initializer: assignment-expression
            ;

/* 3. Statements */

statement: compound-statement
            | expression-statement
            | selection-statement
            | iteration-statement
            | jump-statement
            ;

block-item-list-opt: block-item-list
                    | %empty
                    ;

compound-statement: '{' block-item-list-opt '}'
                    ;

block-item-list: block-item
                | block-item-list block-item
                ;

block-item: declaration
            | statement
            ;

expression-opt: expression
                | %empty
                ;

expression-statement: expression-opt ';'
                    ;

selection-statement: "if" '(' expression ')' statement
                    | "if" '(' expression ')' statement "else" statement
                    ;

iteration-statement: "for" '(' expression-opt ';' expression-opt ';' expression-opt ')' statement
                    ;

jump-statement: "return" expression-opt ';'
                ;

/* 4. Translation Unit */

translation-unit: function-definition
                | declaration
                ;

function-definition: type-specifier declarator compound-statement
                    ;

%%

//c code

void yyerror(const char *s) {
    fprintf(stderr, "%s\n", s);
    exit(EXIT_FAILURE);
}
