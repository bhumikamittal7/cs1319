#include "1_A3.tab.h"
#include <stdio.h>

extern char *yytext;
extern int yyparse();
extern int yylex();


void yyerror(const char *s) {
printf("Error: %s on '%s'\n",s,yytext);
}

int main() 
{
    yyparse();
    return 0;
}
