.PHONY: build clean

output: lexer 1_A3.nc
		./lexer < 1_A3.nc > 1_A3.txt

lexer: lex.yy.c
		gcc lex.yy.c 1_A3.c -o lexer -lfl -Werror

lex.yy.c: 1_A3.l
		flex 1_A3.l

build: clean lexer

clean:
		rm -f lexer lex.yy.c 1_A3.txt