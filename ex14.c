#include <stdio.h>
#include <ctype.h>
#include <strings.h>

// forward declarations
/*
 after processing below forward declarations the compiler would allow the program code to refer to
 these entities in the rest of the program
*/
// how to break it point #1, remove forward declaration  to confuse compiler and cause it to complain
// after getting error about implicit function declaration added back the forward declarations
int can_print_it(char ch);
void print_letters(char arg[], int arg_len);

void print_arguments(int argc, char *argv[])
{
	for(int i = 0; i < argc; i++){
		int argv_len = strlen(argv[i]);
		print_letters(argv[i], argv_len);
	}
}

void print_letters(char arg[], int arg_len)
{
	// extra credit point #2, avoid relying on '\0' to check for string end
	for(int i = 0; i < arg_len; i++){
		char ch = arg[i];
		//isalpha checks if char is alphabetic and isblank checks if char is a blank char
		//this function returns 1 (true) if char is an alphabetic or blank char
		// extra credit point #1, remove can_print_it function (added it as a relation operation)
		if(isalpha(ch) || isblank(ch)){
			printf("'%c' == %d ",ch, ch);
		}
	}
	printf("\n");
}	

int main(int argc, char *argv[])
{
	// how to break it point #2, make argc higher than the actual number of arguments inside argv
	// got segmentation fault after trying to read argv value beyond argv length, commented code that caused the segfault
	//argc += 1;
	print_arguments(argc, argv);
	return 0;
}
