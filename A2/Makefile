output: a.out 1_A2.nc
		./a.out < 1_A2.nc > output.txt

a.out:  lex.yy.c 1_A2.c
		cc lex.yy.c 1_A2.c -lfl

lex.yy.c: 1_A2.l
		flex 1_A2.l

clean:
	rm a.out lex.yy.c output.txt