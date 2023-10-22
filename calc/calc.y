%{
#include <string.h>
#include <iostream>
#include "parser.h"

extern int yylex();
void yyerror(const char *s);
#define NSYMS 20 /* max # of symbols */
symboltable symtab[NSYMS];
%}

%union {
    int intval;
    struct symtab *symp;
}

%token <symp> NAME
%token <intval> NUMBER
%type <intval> expression
%type <intval> term
%type <intval> factor

%%

stmt_list: stmt_list statement '\n'
         | statement '\n'
         ;

statement: NAME '=' expression { $1->value = $3; }
         | expression { printf("= %d\n", $1); }
         ;

expression: expression '+' term { $$ = $1 + $3; }
          | expression '-' term { $$ = $1 - $3; }
          | term
          ;

term: term '*' factor { $$ = $1 * $3; }
    | term '/' factor {
        if ($3 == 0.0)
            yyerror("divide by zero");
        else
            $$ = $1 / $3;
    }
    | factor
    ;

factor: '(' expression ')' { $$ = $2; }
      | '-' factor { $$ = -$2; }
      | NUMBER
      | NAME { $$ = $1->value; }
      ;

struct symtab *symlook(char *s) {
    char *p;
    struct symtab *sp;
    for(sp = symtab; sp < &symtab[NSYMS]; sp++) {
        /* is it already here? */
        if (sp->name && !strcmp(sp->name, s))
            return sp;
        if (!sp->name) {
            /* is it free */
            sp->name = strdup(s);
            return sp;
        }
        /* otherwise continue to next */
    }
    yyerror("Too many symbols");
    exit(1); /* cannot continue */
} /* symlook */

void yyerror(const char *s) {
    std::cout << s << std::endl;
}

int main() {
    yyparse();
}
