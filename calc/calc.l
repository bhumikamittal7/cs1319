%{
#include <math.h>
#include "y.tab.h"
#include "parser.h"
%}

ID      [A-Za-z][A-Za-z0-9]*

%%

[0-9]+      { yylval.intval = atoi(yytext); return NUMBER; } /* set symbol attribute */
[ \t]       ; /* ignore white space */
{ID}        { yylval.symp = symlook(yytext); return NAME; } /* return symbol pointer */
"$"         { return 0; /* end of input */ }
\n | .      return yytext[0];

%%
