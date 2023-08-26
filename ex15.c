#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
	//Extra credit point 3 process command line arguments using just pointers
	int arg_size = sizeof(argv);
	int arg_count = sizeof(argv)/sizeof(argv[0]);	
	printf("arguments passed to main function: %d.\n", arg_count);
	printf("argv size: %d.\n", arg_size);
	printf("argv %p.\n", (void *) argv);
	printf("argv %s.\n", *argv);
	for(int i = 0; i < argc; i++){
		printf("argv %s.\n", *(argv + i));
	}
	// How to break it point #2, invert all loops	
	// create two arrays we care about
	// Extra credit point 1 rewrite all arrays as pointers
	// Extra credit point 2 rewrite all pointers as arrays
	int ages[] = { 23, 43, 12, 89, 2};
	char names[5][5] = { "Alan", "Frank", "Mary", "John", "Lisa"};


	// what does names point to? "Alan"? or just "A"?
	printf("names evaluates to the address: %p.\n", (void *) names);// got an address, need to dereference
	printf("the value pointed at by the names address: %p.\n", (void *) *names);// it prints another address, so it's an array of pointers
	// and this pointers point to the first pointer of the char array, can I get the address of this char array?
	//what is the size of names?
	int names_size = sizeof(names);
	int names_count = sizeof(names)/sizeof(names);
	//int first_str_size = sizeof(*names)/sizeof(char);
	printf("size of names = %d.\n", names_size);
	printf("count of names = %d.\n", names_count);
	//printf("size of first string? : %d.\n", first_str_size);
	printf("value of first string? : %c.\n", *(*names));
	
	// safely get the size of ages
	int count = sizeof(ages)/sizeof(ages[0]);
	
	// first way using indexing
	for(int i = count-1; i >= 0; i--){
		printf("%s is %d years old.\n", names[i], ages[i]);
	}
	printf("---\n");
	
	// set up the pointers to the start of the arrays
	int curr_age[count];
	char curr_name[5][5];
	
	for(int i = 0; i < count; i++){
		curr_age[i] = ages[i];
		strcpy(curr_name[i], names[i]);
	}
	
	// second way using pointers
	for(int i = count-1; i >= 0; i--){
		printf("%s is %d years old.\n", curr_name[i], curr_age[i]);
	}

	printf("---\n");
	
	// third way, pointers are just arrays
	printf("size of ages (in bytes) to which curr_age points to: %ld == %d ints.\n", sizeof(ages), count);
	for(int i = count-1; i >= 0; i--){
		// A difference between pointers and arrays, sizeof pointers just returns the size of pointer type
		// sizeof an array returns the size of the whole array
		printf("size of curr_age int pointer: %ld.\n", sizeof(curr_name));
		printf("%s is %d years old.\n", curr_name[i], curr_age[i]);
	}
	
	printf("---\n");
	return 0;
}
