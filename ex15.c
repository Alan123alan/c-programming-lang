#include <stdio.h>
#include <string.h>

void first_print(int *, int, char *[], int);
void second_prinf(int *, int, char *[]);
void third_print(int *, int, char *[]);


void first_print(int *ages, int ages_count, char *names[], int name_count){
	// first way using indexing
	for(int i = ages_count-1; i >= 0; i--){
		printf("%s is %d years old.\n", names[i], ages[i]);
	}
	printf("---\n");
}

void second_print(int *curr_age, int ages_count, char **curr_name){
	// second way using pointers
	for(int i = ages_count-1; i >= 0; i--){
		printf("%s is %d years old.\n", *(curr_name + i), *(curr_age + i));
	}
	printf("---\n");
}

void third_print(int *curr_age, int ages_count, char **curr_name){
	// third way, pointers are just arrays
	for(int i = ages_count-1; i >= 0; i--){
		// Difference between pointers and arrays:
		// sizeof pointers just returns the size of pointer type
		// sizeof an array returns the size of the whole array
		printf("size of curr_age: %ld.\n", sizeof(curr_name));
		printf("%s is %d years old.\n", curr_name[i], curr_age[i]);
	}
	printf("---\n");
}

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
	char *names[] = { "Alan", "Frank", "Mary", "John", "Lisa"};


	// what does names point to? "Alan"? or just "A"?
	printf("names evaluates to the address: %p.\n", (void *) names);// got an address, need to dereference
	printf("the value pointed at by the names address: %p.\n", (void *) *names);// it prints another address, so it's an array of pointers
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
	int ages_count = sizeof(ages)/sizeof(ages[0]);
	
	// first print function
	first_print(ages, ages_count, names, names_count);

	// set up the pointers to the start of the arrays
	int *curr_age = ages;
	char **curr_name = names;

	// second print function
	second_print(curr_age, ages_count, curr_name);
	
	// third print function
	third_print(curr_age, ages_count, curr_name);

	return 0;
}
