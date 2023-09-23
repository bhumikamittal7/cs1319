output: a.out 1_A2.nc
		./a.out < 1_A2.nc > 1_A2.txt

a.out:  lex.yy.c 1_A2.c
		cc lex.yy.c 1_A2.c -lfl

lex.yy.c: 1_A2.l
		flex 1_A2.l

clean:
	rm a.out lex.yy.c 1_A2.txt