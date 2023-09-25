%{
    #include<stdio.h>
    #define KEYWORD                     2
    #define IDENTIFIER                  3
    #define INTEGER_CONSTANT            4
    #define CHAR_CONSTANT               5
    #define STRING_LITERAL              6
    #define PUNCTUATOR                  7
    #define SINGLE_LINE_COMMENT_START   8
    #define SINGLE_LINE_COMMENT_END     9
    #define MULTI_LINE_COMMENT_START    10
    #define MULTI_LINE_COMMENT_END      11
%}


KEYWORD                 "char"|"else"|"for"|"if"|"int"|"return"|"void"
NONDIGIT                [_a-zA-Z]
DIGIT                   [0-9]
NONDIGIT_DIGIT          [_a-zA-Z0-9]
NON_ZERO_DIGIT          [1-9]
SIGN                    [+|-]
IDENTIFIER              {NONDIGIT}{NONDIGIT_DIGIT}*
INTEGER_CONSTANT        {SIGN}?{NON_ZERO_DIGIT}{DIGIT}*|0
ESCAPE_SEQUENCE         \\[\'\"?\\abfnrtv]
C_CHAR                  [^\'\\\n]|{ESCAPE_SEQUENCE}
C_CHAR_SEQUENCE         {C_CHAR}+
CHARACTER_CONSTANT      \'({C_CHAR_SEQUENCE})\'
Constants               {INTEGER_CONSTANT}|{CHARACTER_CONSTANT}
S_CHAR                  [^\"\\\n]|{ESCAPE_SEQUENCE}
S_CHAR_SEQUENCE         {S_CHAR}+
STRING_LITERAL          \"({S_CHAR_SEQUENCE})\"
PUNCTUATOR              "["|"]"|"("|")"|"{"|"}"|"->"|"&"|"*"|"+"|"-"|"/"|"%"|"!"|"?"|"<"|">"|"<="|">="|"=="|"!="|"&&"|"||"|"="|":"|";"|","
WHITESPACE              [ \t\n]
%x MULTI_LINE_COMMENT
%x SINGLE_LINE_COMMENT

%%

{KEYWORD}                       {return KEYWORD;}
{STRING_LITERAL}                {return STRING_LITERAL;}
{IDENTIFIER}                    {return IDENTIFIER;}
{INTEGER_CONSTANT}              {return INTEGER_CONSTANT;}
{CHARACTER_CONSTANT}            {return CHAR_CONSTANT;}
{PUNCTUATOR}                    {return PUNCTUATOR;}
{WHITESPACE}                    {/*ignore*/}
"//"                            {BEGIN(SINGLE_LINE_COMMENT);return SINGLE_LINE_COMMENT_START;}
<SINGLE_LINE_COMMENT>.          {/*ignore*/}
<SINGLE_LINE_COMMENT>\n         {BEGIN(INITIAL); return SINGLE_LINE_COMMENT_END;}
<SINGLE_LINE_COMMENT><<EOF>>    {BEGIN(INITIAL);return SINGLE_LINE_COMMENT_END;}
"/*"                            {BEGIN(MULTI_LINE_COMMENT); return MULTI_LINE_COMMENT_START;}
<MULTI_LINE_COMMENT>"*/"        {BEGIN(INITIAL); return MULTI_LINE_COMMENT_END;}
<MULTI_LINE_COMMENT>.           {/*ignore*/}
<MULTI_LINE_COMMENT>\n          {/*ignore*/}

%%