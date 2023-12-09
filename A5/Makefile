TARGET = translator
TEST_FILE = 1_A5.nc
OUTPUT_FILE = 1_A5.out

all: $(TARGET)
	./$(TARGET) < $(TEST_FILE) > $(OUTPUT_FILE)

$(TARGET): lex.yy.o 1_A5.tab.o 1_A5_translator.o
	g++ lex.yy.o 1_A5.tab.o 1_A5_translator.o -ll -o $(TARGET) -w

1_A5_translator.o: 1_A5_translator.cxx 1_A5_translator.h
	g++ -c 1_A5_translator.h -w
	g++ -c 1_A5_translator.cxx -w

lex.yy.o: lex.yy.c
	g++ -c lex.yy.c -w -fcompare-debug-second 

1_A5.tab.o: 1_A5.tab.c
	g++ -c 1_A5.tab.c -w -fcompare-debug-second 	

lex.yy.c: 1_A5.l 1_A5.tab.h 1_A5_translator.h
	flex 1_A5.l

1_A5.tab.c 1_A5.tab.h: 1_A5.y
	bison -d 1_A5.y

clean:
	rm lex.yy.c 1_A5.tab.c 1_A5.tab.h lex.yy.o 1_A5.tab.o 1_A5_translator.o $(TARGET) 1_A5_translator.h.gch

build: $(TARGET)

.PHONY: clean build