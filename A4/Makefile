TARGET = translator
TEST_FILE = 1_A4.nc
OUTPUT_FILE = 1_A4.out

all: $(TARGET)
	./$(TARGET) < $(TEST_FILE) > $(OUTPUT_FILE)
	@echo "Test File Successfully Translated !\n"

$(TARGET): lex.yy.o 1_A4.tab.o 1_A4_translator.o
	g++ lex.yy.o 1_A4.tab.o 1_A4_translator.o -ll -o $(TARGET) -Werror

1_A4_translator.o: 1_A4_translator.cxx 1_A4_translator.h
	g++ -c 1_A4_translator.h
	g++ -c 1_A4_translator.cxx

lex.yy.o: lex.yy.c
	g++ -c lex.yy.c

1_A4.tab.o: 1_A4.tab.c
	g++ -c 1_A4.tab.c

lex.yy.c: 1_A4.l 1_A4.tab.h 1_A4_translator.h
	flex 1_A4.l

1_A4.tab.c 1_A4.tab.h: 1_A4.y
	bison -d 1_A4.y

clean:
	rm lex.yy.c 1_A4.tab.c 1_A4.tab.h lex.yy.o 1_A4.tab.o 1_A4_translator.o $(TARGET) 1_A4_translator.h.gch $(OUTPUT_FILE)

build: clean all

.PHONY: clean build
