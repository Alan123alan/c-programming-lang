#include <stdio.h>

int main(int argc, char *argv[])
{
	// How to break it point #2, invert all loops	

	// create two arrays we care about
	int ages[] = { 23, 43, 12, 89, 2};
	char *names[] = { "Alan", "Frank", "Mary", "John", "Lisa"};

	// ages will be the address of the first int in ages
	//printf("ages: %d.\n", ages);
	
	// since ages is already the address with dereference operator we should get the value
	//printf("ages: %d.\n", *ages);

	// then what is returned if we use the address of data operator??
	// my guess is that it will print the same address as just printing ages
	//printf("ages: %d.\n", &ages);

	// what does names point to? "Alan"? or just "A"?
	printf("names: %d.\n", names);// got an address, need to dereference
	printf("names points at: %d.\n", *names);// it prints another address, so it's an array of pointers
	// and this pointers point to the first pointer of the char array, can I get the address of this char array?
	//what is the size of names?
	int names_size = sizeof(names);
	int names_count = sizeof(names)/sizeof(names[0]);
	//int first_str_size = sizeof(*names)/sizeof(char);
	printf("size of names = %d.\n", names_size);
	printf("count of names = %d.\n", names_count);
	//printf("size of first string? : %d.\n", first_str_size);
	printf("value of first string? : %c.\n", *(*names));
	
	// safely get the size of ages
	int count = sizeof(ages)/sizeof(int);
	
	// first way using indexing
	for(int i = count-1; i >= 0; i--){
		printf("%s is %d years old.\n", names[i], ages[i]);
	}
	printf("---\n");
	
	// set up the pointers to the start of the arrays
	int *curr_age = ages;
	char **curr_name = names;
	
	
	// second way using pointers
	for(int i = count-1; i >= 0; i--){
		printf("%s is %d years old.\n", *(curr_name + i), *(curr_age + i));
	}

	printf("---\n");
	
	// third way, pointers are just arrays
	printf("size of ages (in bytes) to which curr_age points to: %ld == %ld ints.\n", sizeof(ages), sizeof(ages)/sizeof(int));
	for(int i = count-1; i >= 0; i--){
		// A difference between pointers and arrays sizeof pointers just returns the size of pointer type
		// sizeof an array returns the size of the whole array
		printf("size of curr_age int pointer: %ld.\n", sizeof(curr_name));
		printf("%s is %d years old.\n", curr_name[i], curr_age[i]);
	}
	
	printf("---\n");

	// fourth way with pointers in a stupid complex way
	for(curr_age = ages + (count-1); (curr_age - ages) >= 0; curr_age--){
		printf("%d years old.\n", *curr_age);
	}
	for(curr_name = names + (names_count-1); (curr_name - names) >= 0; curr_name--){
		printf("%s.\n", *curr_name);
	}
	
	
	// How to break it point #1
	//curr_age = (int**)names;
	//printf("curr_age %d %s.\n", &curr_age, *curr_age);
	return 0;
}
