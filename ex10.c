#include <stdio.h>

int main(int argc, char *argv[])
{
	//in C switch statements are different to if statements
	//C switch statement is really a jump table
	if(argc != 2){
		printf("ERROR: You need one argument.\n");
		return 1;
	}
	int i = 0;
	//go through each arg in argv
	//why is argv[0] skipped? because the first arg in argv is the name of the executable program
	for(i = 0; argv[1][i] != '\0'; i++){
		char letter = argv[1][i];	
		switch(letter){
			//since case 'a' has no break the execution falls through into case A
			case 'a':
			case 'A':
				printf("%d: 'A'\n", i);
				break;
			case 'e':
			case 'E':
				printf("%d: 'E'\n", i);
				break;
			case 'i':
			case 'I':
				printf("%d: 'I'\n", i);
				break;
			case 'o':
			case 'O':
				printf("%d: 'O'\n", i);
				break;
			case 'u':
			case 'U':
				printf("%d: 'U'\n", i);
				break;
			case 'y':
			case 'Y':
				if(i > 2){
					//it's only sometimes y
					printf("%d: 'Y'\n", i);
				}
				break;
			default:
				printf("%d: %c is not a vowel\n", i, letter);
		}
	}
	return 0;
}
