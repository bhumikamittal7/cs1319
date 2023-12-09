TARGET = translator

test: $(TARGET)
	./$(TARGET) 1 > test1.out
	gcc -c test1.asm

	./$(TARGET) 2 > test2.out
	gcc -c test2.asm

	./$(TARGET) 3 > test3.out
	gcc -c test3.asm

	./$(TARGET) 4 > test4.out
	gcc -c test4.asm

	./$(TARGET) 5 > test5.out
	gcc -c test5.asm

	gcc test1.o -o test1 -L. -lio
	gcc test2.o -o test2 -L. -lio
	gcc test3.o -o test3 -L. -lio
	gcc test4.o -o test4 -L. -lio
	gcc test5.o -o test5 -L. -lio

io.a : io.c
	gcc -c io.c
	ar -rcs io.a io.o

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

clean:
	rm lex.yy.c 1_A5.tab.c 1_A5.tab.h lex.yy.o 1_A5.tab.o 1_A5_translator.o $(TARGET) 1_A5_translator.h.gch 1_A5_target_translator.o test1.out test2.out test3.out test4.out test5.out test1.asm test2.asm test3.asm test4.asm test5.asm

build: test

.PHONY: clean build