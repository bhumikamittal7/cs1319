.PHONY: build clean

output: lexer 1_A2.nc
		./lexer < 1_A2.nc > 1_A2.txt

lexer: lex.yy.c
		gcc -Werror lex.yy.c 1_A2.c -o lexer -lfl

lex.yy.c: 1_A2.l
		flex 1_A2.l

build: clean lexer

clean:
		rm -f lexer lex.yy.c 1_A2.txt