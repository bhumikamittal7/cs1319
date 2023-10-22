.PHONY: build clean

output: parser 1_A3.nc
		./parser < 1_A3.nc > 1_A3.txt

lexer: lex.yy.c
		gcc lex.yy.c 1_A3.c -o lexer -lfl -Werror

1_A3.tab.c: 1_A3.y
			bison -d 1_A3.y

lex.yy.c: 1_A3.l
		flex 1_A3.l

parser: 1_A3.tab.c lex.yy.c
		gcc -o parser lex.yy.c 1_A3.tab.c 1_A3.c -lfl

build: clean parser

clean:
		rm -f parser lex.yy.c 1_A3.tab.c 1_A3.tab.h 1_A3.txt