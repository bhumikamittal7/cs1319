output: a.out test.nc
		./a.out < test.nc > test.txt

a.out:  lex.yy.c
		cc lex.yy.c test.c -lfl

lex.yy.c: test.l
		flex test.l

clean:
	rm a.out lex.yy.c test.txt