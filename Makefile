CFLAGS=-Wall -Wextra -pedantic -g

all: ex1 ex3
clean:
	rm -rf ex1 ex1.dSYM/ ex3 ex3.dSYM/ ex7 ex7.dSYM/ ex8 ex8.dSYM ex9 ex9.dSYM ex10 ex10.dSYM ex11 ex11.dSYM ex12 ex12.dSYM ex13 ex13.dSYM ex14 ex14.dSYM ex15 ex15.dSYM ex16 ex16.dSYM
	rm -rf extra10 extra10.dSYM/
cleanSyntaxStructures:
	rm -rf syntax_structures syntax_structures.dSYM
