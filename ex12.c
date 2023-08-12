#include <stdio.h>

int main(int argc, char *argv[])
{
	int areas[] = {10, 12, 13, 14, 20};
	char name[] = "Zed";
	//char full_name[] = {'Z', 'e', 'd', ' ', 'A', '.', ' ', 'S', 'h', 'a', 'w', '\0'};
	//How to break it first point, remove the zero byte terminator from full_name
	char full_name[] = {'Z', 'e', 'd', ' ', 'A', '.', ' ', 'S', 'h', 'a', 'w'};
	//WARNING: On some systems you may have to change the
	// %ld in this code to a %u since it will use unsigned ints
	printf("The size of an int: %ld.\n", sizeof(int));
	printf("The size of areas (int[]): %ld.\n",sizeof(areas));
	printf("The number of ints in areas: %ld.\n", sizeof(areas)/sizeof(int));
	printf("The first area is: %d, the 2nd is: %d.\n", areas[0], areas[1]);
	//How to break it second point, print an out of index char
	printf("There is no int at index 10: %d.\n", areas[10]); 
	printf("The size of a char: %ld.\n", sizeof(char));
	printf("The size of name (char[]): %ld.\n", sizeof(name));
	printf("The number of chars in name: %ld.\n", sizeof(name)/sizeof(char));
	printf("The size of full_name (char[]): %ld.\n", sizeof(full_name));
	printf("The number of chars in full_name (char[]): %ld.\n", sizeof(full_name)/sizeof(char));
	printf("name=\"%s\" and full_name=\"%s\".\n", name, full_name);
	return 0;
}
