#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern int yylex();
extern void yyerror(char *s);
extern char* yytext;

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
#define INVALID_TOKEN               12

void printStuff(char* type) {
    for (int i = 0; yytext[i] != '\0'; i++) {
        printf("%c", yytext[i]);
    }
    printf(">\n");
}

int lexer(){
    int token;
    while ((token = yylex())) 
    {
        if (token == KEYWORD) 
        {
            printf("<KEYWORD, %s>\n", yytext);
        }
        else if (token == IDENTIFIER) 
        {
            printf("<IDENTIFIER, %s>\n", yytext);
        }
        else if (token == INTEGER_CONSTANT) 
        {
            printf("<CONSTANT, %s>\n", yytext);
        }
        else if (token == CHAR_CONSTANT) 
        {
            printf("<CONSTANT, ");
            printStuff(yytext);
        }
        else if (token == STRING_LITERAL) 
        {
            printf("<STRING-LITERAL, ");
            printStuff(yytext);
        }
        else if (token == PUNCTUATOR) 
        {
            printf("<PUNCTUATOR, %s>\n", yytext);
        }
        else if ((token == SINGLE_LINE_COMMENT_START) ||  (token == SINGLE_LINE_COMMENT_END) ||(token == MULTI_LINE_COMMENT_START) || (token == MULTI_LINE_COMMENT_END) )
        {
            // do nothing
        }
        else 
        {
            printf("<INVALID_TOKEN, %s>\n", yytext);
            return *yytext;
        }
    }
    return 0;
}

int main() 
{
    lexer();
    yyparse();

    return 0;
}
