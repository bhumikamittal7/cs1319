TARGET = translator

test: $(TARGET) io.a
	./$(TARGET) 1 > test1.out
	gcc -c 1_A5_quads1.asm

	./$(TARGET) 2 > test2.out
	gcc -c 1_A5_quads2.asm

	./$(TARGET) 3 > test3.out
	gcc -c 1_A5_quads3.asm

	./$(TARGET) 4 > test4.out
	gcc -c 1_A5_quads4.asm

	./$(TARGET) 5 > test5.out
	gcc -c 1_A5_quads5.asm

	gcc -L. -lio io.o -o test1
	gcc -L. -lio io.o -o test2

$(TARGET): lex.yy.o 1_A5.tab.o 1_A5_translator.o 1_A5_target_translator.o
	g++ lex.yy.o 1_A5.tab.o 1_A5_translator.o 1_A5_target_translator.o -ll -o $(TARGET) -Werror

1_A5_target_translator.o: 1_A5_target_translator.cxx 
	g++ -c 1_A5_target_translator.cxx

1_A5_translator.o: 1_A5_translator.cxx 1_A5_translator.h
	g++ -c 1_A5_translator.h
	g++ -c 1_A5_translator.cxx

lex.yy.o: lex.yy.c
	g++ -c lex.yy.c 

1_A5.tab.o: 1_A5.tab.c
	g++ -c 1_A5.tab.c

lex.yy.c: 1_A5.l 1_A5.tab.h 1_A5_translator.h
	flex 1_A5.l

1_A5.tab.c 1_A5.tab.h: 1_A5.y
	bison -d 1_A5.y

io.a : io.c
	gcc -c io.c
	ar -rcs io.a io.o

clean:
	rm lex.yy.c 1_A5.tab.c 1_A5.tab.h lex.yy.o 1_A5.tab.o 1_A5_translator.o $(TARGET) 1_A5_translator.h.gch 1_A5_target_translator.o io.a io.o

build: test

.PHONY: clean build