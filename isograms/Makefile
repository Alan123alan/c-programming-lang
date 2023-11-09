CC=cc
CFLAGS=-Wall -Wextra -pedantic -g

main: 
	$(CC) $(CFLAGS) isograms.c -o isograms
tests:
	$(CC) $(CFLAGS) Testisograms.c isograms.c ../test-framework/Unity/src/unity.c -o Testisograms
clean:
	rm -rf isograms isograms.dSYM/
	rm -rf Testisograms Testisograms.dSYM/
