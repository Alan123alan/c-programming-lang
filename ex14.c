#include <stdio.h>
#include <ctype.h>

// forward declarations
/*
 after processing below forward declarations the compiler would allow the program code to refer to
 these entities in the rest of the program
*/
int can_print_it(char ch);
void print_letters(char arg[]);

void print_arguments(int argc, char *argv[])
{
	for(int i = 0; i < argc; i++){
		print_letters(argv[i]);
	}
}

void print_letters(char arg[])
{
	for(int i = 0; arg[i] != '\0'; i++){
		char ch = arg[i];
		if(can_print_it(ch)){
			printf("'%c' == %d ",ch, ch);
		}
	}
	printf("\n");
}	

int can_print_it(char ch)
{
	//isalpha checks if char is alphabetic and isblank checks if char is a blank char
	//this function returns 1 (true) if char is an alphabetic or blank char
	return isalpha(ch) || isblank(ch);
}

int main(int argc, char *argv[])
{
	print_arguments(argc, argv);
	return 0;
}
