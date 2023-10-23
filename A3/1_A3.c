#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "1_A3.tab.h"

extern int yylex();
extern void yyerror(const char *);
extern char* yytext;

int main() 
{
    yyparse();
    printf("Lesgoo!\n");
    return 0;
}
