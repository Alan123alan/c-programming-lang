CC=cc
CFLAGS=-Wall -Wextra -pedantic -g

all: list_ops 
tests:
	$(CC) $(CFLAGS) Testlist_ops.c list_ops.c test-framework/Unity/src/unity.c -o Testlist_ops
clean:
	rm -rf list_ops list_ops.dSYM/
	rm -rf Testlist_ops Testlist_ops.dSYM/
