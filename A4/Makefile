.SUFFIXES: 

translator: 1_A4.y 1_A4_translator.cxx 1_A4.l
	bison -d 1_A4.y
	flex -o lex.yy.c 1_A4.l
	g++ 1_A4_translator.cxx 1_A4.tab.c lex.yy.c -lfl -Werror -o translator

build: translator

test: translator
	./translator < 1_A4.nc >1_A4.out

clean:
		rm -f lex.yy.c translator 1_A4.tab.c 1_A4.tab.h 1_A4.tab.o lex.yy.o 1_A4.out