.PHONY: build clean

output: parser calc.nc
		./parser < calc.nc > calc.txt

lexer: lex.yy.c
		gcc lex.yy.c calc.c -o lexer -lfl -Werror

parser: calc.tab.c
		gcc -o parser lex.yy.c calc.tab.c calc.c -lfl -Werror

calc.tab.c: calc.y
			bison -d calc.y

lex.yy.c: calc.l
		flex calc.l

build: clean parser

clean:
		rm -f parser lex.yy.c calc.tab.c calc.txt