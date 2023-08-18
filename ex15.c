#include <stdio.h>

int main(int argc, char *argv[])
{
	// create two arrays we care about
	int ages[] = { 23, 43, 12, 89, 2};
	char *names[] = { "Alan", "Frank", "Mary", "John", "Lisa"};

	// ages will be the address of the first int in ages
	printf("ages: %d.\n", ages);
	
	// since ages is already the address with dereference operator we should get the value
	printf("ages: %d.\n", *ages);

	// then what is returned if we use the address of data operator??
	// my guess is that it will print the same address as just printing ages
	printf("ages: %d.\n", &ages);
	
	// safely get the size of ages
	int count = sizeof(ages)/sizeof(int);
	
	// first way using indexing
	for(int i = 0; i < count; i++){
		printf("%s is %d years old.\n", names[i], ages[i]);
	}
	printf("---\n");
	
	// set up the pointers to the start of the arrays
	int *curr_age = ages;
	char **curr_name = names;
	
	// second way using pointers
	for(int i = 0; i < count; i++){
		printf("%s is %d years old.\n", *(curr_name + i), *(curr_age + i));
	}

	printf("---\n");
	
	// third way, pointers are just arrays
	for(int i = 0; i < count; i++){
		printf("%s is %d years old.\n", curr_name[i], curr_age[i]);
	}
	
	printf("---\n");

	// fourth way with pointers in a stupid complex way
	for(curr_name = names, curr_age = ages; (curr_age - ages) < count; curr_name++, curr_age++){
		printf("%s is %d years old.\n", *curr_name, *curr_age);
	}
	return 0;
}