#include <stdio.h>

int main(int argc, char *argv[])
{
	//in C switch statements are different to if statements
	//C switch statement is really a jump table
	int i = 0;
	//go through each arg in argv
	//why is argv[0] skipped? because the first arg in argv is the name of the executable program
	for(i = 1; i < argc; i++){
		printf("arg #%d: %s.\n", i, argv[i]);
	}
	//let's make our own array of strings
	char *states[] = {"California", "Oregon", "Washington", "Texas"};

	int num_states = 4;
	
	for(i = 0; i < num_states; i++){
		printf("state #%d: %s.\n", i, states[i]);
	}
	return 0;
}
