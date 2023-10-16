// stdio.h adds code to perform input and output operations
#include <stdio.h>
// assert.h is a header file from standard library 
// in which the assert debugging macro is defined
// this macro expands into an if block in which a test condition is tested
// if the test evaluates to 0 (false) then the program is aborted using
// the abort() function an a message is printed in stderr
#include <assert.h>
// stdlib.h is the header file of the C standard library
// it contains the function prototypes for dynamic memory management,
// process control, etc.
#include <stdlib.h>
// string.h contains useful fuctions for string manipulation
#include <string.h>

// adding a typedef struct to avoid having to type struct Person everytime
// typedef struct Person Person;

// defines a struct named Person with 4 fields
// preferred way to declare a struct
typedef struct {
	char *name;
	int age;
	int height;
	int weight;
} Person;

// we are defining a function named Person_create that returns a pointer to
// a Person struct
Person *Person_create(char *name, int age, int height, int weight){
	// allocates memory in heap with the size of struct Person
	// an returns a pointer to the memory block
	Person *who = malloc(sizeof(Person));
	// checking that malloc operation didn't return a NULL invalid pointer
	assert(who != NULL);
	// strdup function used to duplicate the string for name
	// to make sure this structure actually owns it	
	who->name = strdup(name);
	who->age = age;
	who->height = height;
	who->weight = weight;
	
	return who;
}

// IMPORTANT: if you have a create function then a destroy function is always
// needed
void Person_destroy(Person *who){
	// checking that the pointer to Person struct passed as argument
	// is not a NULL invalid pointer
	assert(who != NULL);
	// freeing the memory allocated by strdup function
	free(who->name);
	// freeing the memory allocated by malloc
	free(who);
}

// a function that takes a pointer to a Person struct
// dereferences their members and prints them
void Person_print(Person *who){
	printf("Name: %s.\n", who->name);
	printf("Age: %d.\n", who->age);
	printf("Height: %d.\n", who->height);
	printf("Weight: %d.\n", who->weight);
}

// code for Extra Credit point 3, pass a structure by value not by pointer
void Person_print_stack(Person who){
	printf("Name: %s.\n", who.name);
	printf("Age: %d.\n", who.age);
	printf("Height: %d.\n", who.height);
	printf("Weight: %d.\n", who.weight);
}

int main(int argc, char *argv[]){
	// Extra Credit point 1 and 2: create all structs on the stack
	// and initialize it using the '.' char instead of '->'
	Person jane;  
	// seems like when a struct is created on the stack you need
	// to use '.' to access the struct members
	jane.name = "Jane";
        jane.age = 23;
        jane.height = 23;
        jane.weight = 23;
	Person_print_stack(jane);
	//printf("name: %s, age: %d.\n", jane.name, jane.age);
	// make people structures
	Person *joe = Person_create("Joe Alex", 32, 64, 100);
	Person *frank = Person_create("Frank Blank", 20, 72, 180);
	
	// print them out and where they are in memory
	printf("Joe is at memory location: %p.\n", joe);
	Person_print(joe);

	printf("Frank is at memory location: %p.\n", frank);
	Person_print(frank);
	
	// make everyone age 20 years and print them again
	joe->age += 20;
	joe->height -= 2;
	joe->weight += 40;
	Person_print(joe);

	frank->age += 20;
	frank->weight += 20;
	Person_print(frank);

	// destroy them both so we clean up
	Person_destroy(joe);
	// code added for 'How To Break It' point #1
	//Person_destroy(NULL);
	// code commented for 'How To Break It' point #2
	Person_destroy(frank);
	// no Valgrind available to detect memory leaks, 
        // used Mac command: leaks --atExit -- ./ex16
	// to get memory leak info to confirm that leak corresponds to Person struct frank
	// print and confirm that address matches leak
	printf("frank address %p.\n", frank);

	return 0;
}
