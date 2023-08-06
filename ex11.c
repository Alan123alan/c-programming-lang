#include <stdio.h>

/*
TO DO: 
 - implement a function that takes a 4 byte long string (or char array) and returns an int
 - implement a function that takes a 4 byte integer and returns a 4 byte long string (or char array)
*/

int main(int argc, char *argv[])
{
	int numbers[4] = { 0 };
	char name[4] = { 'a' };
	//first print them out raw
	printf("number [0]: %d, [1]: %d, [2]: %d, [3]: %d.\n", numbers[0], numbers[1], numbers[2], numbers[3]);
	printf("name [0]: %c, [1]: %c, [2]: %c, [3]: %c.\n", name[0], name[1], name[2], name[3]);
	printf("name : %s.\n", name);
	//set up the numbers
	numbers[0] = 1;
	numbers[1] = 2;
	numbers[2] = 3;
	numbers[3] = 4;
	//set up the name
	name[0] = 'Z';
	name[1] = 'e';
	name[2] = 'd';
	name[3] = '\0';
	//then print with initialized values
	printf("number [0]: %d, [1]: %d, [2]: %d, [3]: %d.\n", numbers[0], numbers[1], numbers[2], numbers[3]);
	printf("name [0]: %c, [1]: %c, [2]: %c, [3]: %c.\n", name[0], name[1], name[2], name[3]);
	printf("name : %s.\n", name);
	//another way to use a name
	char *another = "Zed";
	printf("another name : %s.\n", another);
	printf("another name [0]: %c, [1]: %c, [2]: %c, [3]: %c.\n", another[0], another[1], another[2], another[3]);
	numbers[0] = 'q';
	numbers[1] = 'w';
	numbers[2] = 'i';
	numbers[3] = 'o';
	//no compiler warnings after assigning chars to an int array
	printf("number [0]: %d, [1]: %d, [2]: %d, [3]: %d.\n", numbers[0], numbers[1], numbers[2], numbers[3]);
	name[0] = 113;
	name[1] = 119;
	name[2] = 105;
	name[3] = 0;
	//no compiler warnings after assigning ints to a char array
	printf("name [0]: %c, [1]: %c, [2]: %c, [3]: %c.\n", name[0], name[1], name[2], name[3]);
	printf("name : %s.\n", name);
	return 0;
}
