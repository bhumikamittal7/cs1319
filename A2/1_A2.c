#include <stdio.h>
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

extern char* yytext;
extern int yylex();

int main() 
{
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
            printf("<INTEGER_CONSTANT, %s>\n", yytext);
        }
        else if (token == CHAR_CONSTANT) 
        {
            printf("<CHAR CONSTANT, ");
            for (int i = 1; yytext[i+1] != '\0'; i++)
            {
                printf("%c", yytext[i]);
            }
            printf(">\n");
        }
        else if (token == STRING_LITERAL) 
        {
            printf("<STRING_LITERAL, ");
            for (int i = 1; yytext[i+1] != '\0'; i++)
            {
                printf("%c", yytext[i]);
            }
            printf(">\n");
        }
        else if (token == PUNCTUATOR) 
        {
            printf("<PUNCTUATOR, %s>\n", yytext);
        }
        else if (token == SINGLE_LINE_COMMENT_START) 
        {
            printf("<SINGLE_LINE_COMMENT_START, %s>\n", yytext);
        }
        else if (token == SINGLE_LINE_COMMENT_END) 
        {
            printf("<SINGLE_LINE_COMMENT_END, \"\\n\">\n");
        }
        else if (token == MULTI_LINE_COMMENT_START) 
        {
            printf("<MULTI_LINE_COMMENT_START, %s>\n", yytext);
        }
        else if (token == MULTI_LINE_COMMENT_END) 
        {
            printf("<MULTI_LINE_COMMENT_END, %s>\n", yytext);
        }
        else 
        {
            printf("<INVALID_TOKEN, %s>\n", yytext);
        }
    }
    return 0;
}
