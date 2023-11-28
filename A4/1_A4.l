%{
    /*added here*/

    #include <stdio.h>  
	#include <string.h>
    #include "1_A4_translator.h"

    /*added here ends*/
    
    #include "1_A4.tab.h"


%}


NONDIGIT                [_a-zA-Z]
DIGIT                   [0-9]
NONDIGIT_DIGIT          [_a-zA-Z0-9]
NON_ZERO_DIGIT          [1-9]
SIGN                    [+|-]

IDENTIFIER              {NONDIGIT}{NONDIGIT_DIGIT}*
INTEGER_CONSTANT        0?{NON_ZERO_DIGIT}{DIGIT}*|0

ESCAPE_SEQUENCE         \\[\'\"?\\abfnrtv]
C_CHAR                  [^\'\\\n]|{ESCAPE_SEQUENCE}
C_CHAR_SEQUENCE         {C_CHAR}+
CHARACTER_CONSTANT      \'({C_CHAR_SEQUENCE})\'
Constants               {INTEGER_CONSTANT}|{CHARACTER_CONSTANT}
S_CHAR                  [^\"\\\n]|{ESCAPE_SEQUENCE}
S_CHAR_SEQUENCE         {S_CHAR}+
STRING_LITERAL          \"({S_CHAR_SEQUENCE})*\"
WHITESPACE              [ \t\n]
%x MULTI_LINE_COMMENT
%x SINGLE_LINE_COMMENT
INVALID_TOKEN           .

%%
"char"                          {return CHAR;}
"else"                          {return ELSE;}
"for"                           {return FOR;}
"if"                            {return IF;}
"int"                           {return INT;}
"return"                        {return RETURN;}
"void"                          {return VOID;}


 /*edited here*/
{STRING_LITERAL}                {   yylval.char_value = yytext;
                                    return STRING_LITERAL;}

{IDENTIFIER}                    {   yylval.sym = ST -> lookup(yytext);
                                    return IDENTIFIER;}

{INTEGER_CONSTANT}              {   yylval.intval = atoi(yytext);
                                    return INTEGER_CONSTANT;}

{CHARACTER_CONSTANT}            {   yylval.char_value = yytext[1];
                                    return CHARACTER_CONSTANT;}

/*edited here ends*/


"["                             {return L_SQUARE_BRACKET;}
"]"                             {return R_SQUARE_BRACKET;}
"("                             {return L_ROUND_BRACKET;}
")"                             {return R_ROUND_BRACKET;}
"{"                             {return L_CURLY_BRACKET;}
"}"                             {return R_CURLY_BRACKET;}
"->"                            {return ARROW;}
"&"                             {return AMPERSAND;}
"*"                             {return ASTERISK;}
"+"                             {return PLUS;}
"-"                             {return MINUS;}
"/"                             {return DIVIDE;}
"%"                             {return MODULO;}
"!"                             {return NOT;}
"?"                             {return QUESTION;}
"<"                             {return LESS_THAN;}
">"                             {return GREATER_THAN;}
"<="                            {return LESS_THAN_EQUAL_TO;}
">="                            {return GREATER_THAN_EQUAL_TO;}
"=="                            {return EQUAL_TO;}
"!="                            {return NOT_EQUAL_TO;}
"&&"                            {return LOGICAL_AND;}
"||"                            {return LOGICAL_OR;}
"="                             {return ASSIGN;}
":"                             {return COLON;}
";"                             {return SEMICOLON;}
","                             {return COMMA;}



{WHITESPACE}                    {/*ignore*/}
"//"                            {BEGIN(SINGLE_LINE_COMMENT);/*ignore*/}
<SINGLE_LINE_COMMENT>.          {/*ignore*/}
<SINGLE_LINE_COMMENT>\n         {BEGIN(INITIAL); /*ignore*/}
<SINGLE_LINE_COMMENT><<EOF>>    {BEGIN(INITIAL);/*ignore*/}
"/*"                            {BEGIN(MULTI_LINE_COMMENT); /*ignore*/}
<MULTI_LINE_COMMENT>"*/"        {BEGIN(INITIAL); /*ignore*/}
<MULTI_LINE_COMMENT>.           {/*ignore*/}
<MULTI_LINE_COMMENT>\n          {/*ignore*/}
{INVALID_TOKEN}                 {return INVALID_TOKEN;}

%%