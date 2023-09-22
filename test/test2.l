%{
    #include <stdio.h>
    #include<stdlib.h>
%}

DIGIT [0-9]
ALPH [a-zA-Z]

%%
{DIGIT}{
    printf("Digit: %s\n, yytext);
    return 2
}

{ALPH}{
    printf("Alphabet: %s\n, yytext);
    return 3
}

.{
    printf("Invalid: %s\n, yytext);
    return yywrap()
}
%%

int yywrap(){
    return 1
}