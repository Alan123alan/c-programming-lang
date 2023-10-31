CC=cc
CFLAGS=-Wall -Wextra -pedantic -g

tests:
	$(CC) $(CFLAGS) Testgrade_school.c grade_school.c test-framework/Unity/src/unity.c -o Testgrade_school

main:
	$(CC) $(CFLAGS) grade_school.c -o grade_school

clean:
	rm -rf grade_school grade_school.dSYM
