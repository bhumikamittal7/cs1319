/* Bison Specification for nanoC */

%{
#include <string.h>
#include <iostream>
#include <stdlib.h>
extern int yylex();

void yyerror(const char *s);
%}

%token KEYWORD IDENTIFIER CONSTANT STRING_LITERAL PUNCTUATOR

%left '+' '-'
%left '*' '/' '%'
%left '<' '>' '<=' '>='
%left '==' '!='
%left '&&'
%left '||'
%right '='

%%

program:
    translation-unit
    ;

/* Expressions */

primary-expression:
    IDENTIFIER
    | CONSTANT
    | STRING_LITERAL
    | '(' expression ')'
    ;

postfix-expression:
    primary-expression
    | postfix-expression '[' expression ']'
    | postfix-expression '(' argument-expression-list_opt ')'
    | postfix-expression "->" IDENTIFIER
    ;

argument-expression-list_opt:
    /* Empty */
    | argument-expression-list
    ;

argument-expression-list:
    assignment-expression
    | argument-expression-list ',' assignment-expression
    ;

unary-expression:
    postfix-expression
    | unary-operator unary-expression
    ;

unary-operator:
    '&' | '*' | '+' | '-' | '!'
    ;

multiplicative-expression:
    unary-expression
    | multiplicative-expression '*' unary-expression
    | multiplicative-expression '/' unary-expression
    | multiplicative-expression '%' unary-expression
    ;

additive-expression:
    multiplicative-expression
    | additive-expression '+' multiplicative-expression
    | additive-expression '-' multiplicative-expression
    ;

relational-expression:
    additive-expression
    | relational-expression '<' additive-expression
    | relational-expression '>' additive-expression
    | relational-expression '<=' additive-expression
    | relational-expression '>=' additive-expression
    ;

equality-expression:
    relational-expression
    | equality-expression '==' relational-expression
    | equality-expression '!=' relational-expression
    ;

logical-AND-expression:
    equality-expression
    | logical-AND-expression '&&' equality-expression
    ;

logical-OR-expression:
    logical-AND-expression
    | logical-OR-expression '||' logical-AND-expression
    ;

conditional-expression:
    logical-OR-expression
    | logical-OR-expression '?' expression ':' conditional-expression
    ;

assignment-expression:
    conditional-expression
    | unary-expression '=' assignment-expression
    ;

expression:
    assignment-expression
    ;

/* Declarations */

declaration:
    type-specifier init-declarator ';'
    ;

type-specifier:
    VOID
    | CHAR
    | INT
    ;

init-declarator:
    declarator
    | declarator '=' initializer
    ;

declarator:
    pointer_opt direct-declarator
    ;

pointer_opt:
    /* Empty */
    | pointer
    ;

pointer:
    '*'
    ;

direct-declarator:
    IDENTIFIER
    | IDENTIFIER '[' CONSTANT ']'
    | IDENTIFIER '(' parameter-list_opt ')'
    ;

parameter-list_opt:
    /* Empty */
    | parameter-list
    ;

parameter-list:
    parameter-declaration
    | parameter-list ',' parameter-declaration
    ;

parameter-declaration:
    type-specifier pointer_opt IDENTIFIER
    ;

initializer:
    assignment-expression
    ;

/* Statements */

statement:
    compound-statement
    | expression-statement
    | selection-statement
    | iteration-statement
    | jump-statement
    ;

compound-statement:
    '{' block-item-list_opt '}'
    ;

block-item-list_opt:
    /* Empty */
    | block-item-list
    ;

block-item-list:
    block-item
    | block-item-list block-item
    ;

block-item:
    declaration
    | statement
    ;

expression-statement:
    expression_opt ';'
    ;

expression_opt:
    /* Empty */
    | expression
    ;

selection-statement:
    IF '(' expression ')' statement
    | IF '(' expression ')' statement ELSE statement
    ;

iteration-statement:
    FOR '(' expression_opt ';' expression_opt ';' expression_opt ')' statement
    ;

jump-statement:
    RETURN expression_opt ';'
    ;

/* Translation Unit */

translation-unit:
    function-definition
    | declaration
    ;

function-definition:
    type-specifier declarator compound-statement
    ;
%%

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
    exit(EXIT_FAILURE);
}

int main() {
    yyparse();
    return 0;
}