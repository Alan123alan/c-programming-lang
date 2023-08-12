#include <stdio.h>

int main(int argc, char *argv[])
{
	// go through each string in argv

	// why am I skipping over argv[0]? because argv[0] is the program name
	for(int i = 1; i < argc; i++){
		printf("arg #%d: %s.\n", i, argv[i]);
	}
	// let's make our own array of strings
	char *states[] = { "Oregon", "California", "Arizona", "Colorado"};
	int num_of_states = 4;
	for(int i = 0; i < num_of_states; i++)
	{
		printf("State %d: %s.\n", i, states[i]);
	}	
	return 0;
}
