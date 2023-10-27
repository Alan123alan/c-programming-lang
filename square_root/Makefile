CC = cc
CFLAGS=-Wall -Wextra -pedantic -g

all: square_root 
tests:
	$(CC) $(CFLAGS) Testsquare_root.c square_root.c ./test-framework/Unity/src/unity.c -o Testsquare_root
clean:
	rm -rf square_root square_root.dSYM/
	rm -rf Testsquare_root Testsquare_root.dSYM/
