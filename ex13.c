#include <stdio.h>

int main(int argc, char *argv[])
{
	// go through each string in argv

	// why am I skipping over argv[0]? because argv[0] is the program name
	// how to break it point 2, initialize i to 0
	for(int i = 0; i < argc; i++){//initializing to 0 works because the first argv is the program name
		printf("arg #%d: %s.\n", i, argv[i]);
	}
	// let's make our own array of strings
	char *states[] = { "Oregon", "California", "Arizona", "Colorado"};
	// how to break it point 3, set num_of_states to a value higher to the elements contained in states strings array
	int num_of_states = 5;
	for(int i = 0; i < num_of_states; i++)
	{
		printf("State %d: %s.\n", i, states[i]);
	}	
	return 0;
}
