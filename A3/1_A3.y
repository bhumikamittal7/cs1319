/* test file from slide 06.14 */

%{ 
#include <stdio.h>

extern int yylex();
void yyerror(const char *s);

%}


%token VOID CHAR INT IF ELSE FOR RETURN 
%token IDENTIFIER INTEGER_CONSTANT CHARACTER_CONSTANT STRING_LITERAL 
%token L_SQUARE_BRACKET R_SQUARE_BRACKET L_ROUND_BRACKET R_ROUND_BRACKET L_CURLY_BRACKET R_CURLY_BRACKET 
%token ARROW AMPERSAND ASTERISK PLUS MINUS DIVIDE MODULO NOT QUESTION 
%token LESS_THAN GREATER_THAN LESS_THAN_EQUAL_TO GREATER_THAN_EQUAL_TO EQUAL_TO NOT_EQUAL_TO 
%token LOGICAL_AND LOGICAL_OR ASSIGN COLON SEMICOLON COMMA INVALID_TOKEN

%start translation_unit

%%

/* 1. Expressions */

constant: INTEGER_CONSTANT 
        | CHARACTER_CONSTANT
        ;

primary_expression : IDENTIFIER { printf("primary-expression\n"); }
                    | constant  { printf("primary-expression\n"); }
                    | STRING_LITERAL    { printf("primary-expression\n"); }
                    | L_ROUND_BRACKET expression R_ROUND_BRACKET    { printf("primary-expression\n"); }
                    ;

argument_expression_list_opt: argument_expression_list 
                            | %empty
                            ;

postfix_expression: primary_expression  { printf("postfix-expression\n"); }
                    | postfix_expression L_SQUARE_BRACKET expression R_SQUARE_BRACKET   { printf("postfix-expression\n");}
                    | postfix_expression L_ROUND_BRACKET argument_expression_list_opt R_ROUND_BRACKET   { printf("postfix-expression\n");}
                    | postfix_expression ARROW IDENTIFIER /* pointer indirection only one level */  { printf("postfix-expression\n");}
                    ;

argument_expression_list: assignment_expression { printf("argument-expression-list\n"); }
                        | argument_expression_list COMMA assignment_expression  { printf("argument-expression-list\n"); }
                        ;

unary_expression: postfix_expression    { printf("unary-expression\n");}
                | unary_operator unary_expression   /* this is done to make it non associative, use unary_operator unary_expression */ { printf("unary-expression\n");}
                /* only a single prefix op is allowed - check here again */
                ;

unary_operator: AMPERSAND { printf("unary-operator\n");}
                | ASTERISK  { printf("unary-operator\n");}
                | PLUS  { printf("unary-operator\n");}
                | MINUS     { printf("unary-operator\n");}
                | NOT   { printf("unary-operator\n");}
                ;

multiplicative_expression: unary_expression     /* these are left associative */    { printf("multiplicative-expression\n");}
                            | multiplicative_expression ASTERISK unary_expression   { printf("multiplicative-expression\n");}
                            | multiplicative_expression DIVIDE unary_expression     { printf("multiplicative-expression\n");}
                            | multiplicative_expression MODULO unary_expression     { printf("multiplicative-expression\n");}
                            ;

additive_expression: multiplicative_expression  /* these are left associative */        { printf("additive-expression\n");}
                    | additive_expression PLUS multiplicative_expression                { printf("additive-expression\n");}
                    | additive_expression MINUS multiplicative_expression               { printf("additive-expression\n");}
                    ;

relational_expression: additive_expression      /* these are left associative */        { printf("relational-expression\n");}
                        | relational_expression LESS_THAN additive_expression           { printf("relational-expression\n");}
                        | relational_expression GREATER_THAN additive_expression           { printf("relational-expression\n");}
                        | relational_expression LESS_THAN_EQUAL_TO additive_expression      { printf("relational-expression\n");}
                        | relational_expression GREATER_THAN_EQUAL_TO additive_expression   { printf("relational-expression\n");}
                        ;

equality_expression: relational_expression      /* these are left associative */        { printf("equality-expression\n");}
                    | equality_expression EQUAL_TO relational_expression                { printf("equality-expression\n");}
                    | equality_expression NOT_EQUAL_TO relational_expression            { printf("equality-expression\n");}
                    ;       

logical_AND_expression: equality_expression     /* these are left associative */        { printf("logical-AND-expression\n");}
                        | logical_AND_expression LOGICAL_AND equality_expression        { printf("logical-AND-expression\n");}
                        ;   

logical_OR_expression: logical_AND_expression   /* these are left associative */        { printf("logical-OR-expression\n");}
                        | logical_OR_expression LOGICAL_OR logical_AND_expression       { printf("logical-OR-expression\n");}
                        ;

conditional_expression: logical_OR_expression   /* these are right associative */       { printf("conditional-expression\n");}
                        | logical_OR_expression QUESTION expression COLON conditional_expression    { printf("conditional-expression\n");}
                        ;

assignment_expression: conditional_expression   /* these are right associative */       { printf("assignment-expression\n");}
                        | unary_expression ASSIGN assignment_expression                 { printf("assignment-expression\n");}
                        ;

expression: assignment_expression           { printf("expression\n");}
            ;

/* 2. Declaration */    

declaration: type_specifier init_declarator SEMICOLON   { printf("declaration\n");}
            ;

init_declarator: declarator { printf("init_declarator\n");}
                | declarator ASSIGN initializer { printf("init-declarator\n");}
                ;

type_specifier: VOID    { printf("type-specifier\n");}
                | CHAR  { printf("type-specifier\n");}
                | INT   { printf("type-specifier\n");}
                ;

pointer_opt: pointer   
            | %empty    
            ;

declarator: pointer_opt direct_declarator   { printf("declarator\n"); }
            ;

parameter_list_opt: parameter_list          
                    | %empty               
                    ;

direct_declarator: IDENTIFIER         { printf("direct-declarator\n"); }
                    | IDENTIFIER L_SQUARE_BRACKET INTEGER_CONSTANT R_SQUARE_BRACKET   /* check here again */    { printf("direct-declarator\n"); }
                    | IDENTIFIER L_ROUND_BRACKET parameter_list_opt R_ROUND_BRACKET     { printf("direct-declarator\n"); }
                    ;

pointer: ASTERISK   { printf("pointer\n"); }
        ;

parameter_list: parameter_declaration   { printf("parameter-list\n"); }
                | parameter_list COMMA parameter_declaration    { printf("parameter-list\n"); }
                ;

identifier_opt: IDENTIFIER  
                | %empty   
                ;

parameter_declaration: type_specifier pointer_opt identifier_opt    { printf("parameter-declaration\n"); }
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

block_item_list_opt: block_item_list    
                    | %empty           
                    ;

compound_statement: L_CURLY_BRACKET block_item_list_opt R_CURLY_BRACKET  { printf("compound-statement\n"); }
                    ;   

block_item_list: block_item     { printf("block-item-list\n"); }
                | block_item_list block_item    { printf("block-item-list\n"); }
                ;

block_item: declaration  { printf("block-item\n"); }
            | statement     { printf("block-item\n"); }
            ;

expression_opt: expression  
                | %empty   
                ;

expression_statement: expression_opt SEMICOLON  { printf("expression-statement\n"); }
                    ;

selection_statement: IF L_ROUND_BRACKET expression R_ROUND_BRACKET statement    { printf("selection-statement\n"); }
                    | IF L_ROUND_BRACKET expression R_ROUND_BRACKET statement ELSE statement    { printf("selection-statement\n"); }
                    ;

iteration_statement: FOR L_ROUND_BRACKET expression_opt SEMICOLON expression_opt SEMICOLON expression_opt R_ROUND_BRACKET statement   { printf("iteration-statement\n"); }
                    ;

jump_statement: RETURN expression_opt SEMICOLON   { printf("jump-statement\n"); }
                ;

/* 4. Translation Unit */

translation_unit: function_definition   { printf("translation-unit\n"); }
                | declaration        { printf("translation-unit\n"); }
                ;

function_definition: type_specifier declarator compound_statement   { printf("function-definition\n"); }
                    ;

%%

//c code
