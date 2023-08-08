#include <stdio.h>

int main(int argc, char *argv[])
{
	if(argc != 2){
		printf("Error: You need one argument.\n");
		//this is how you abort a program
		return 1;
	}
	for(int i = 0; argv[1][i] != '\0'; i++){
		char letter = argv[1][i];
		if(letter == 65 || letter == 69 || letter == 73 || letter == 79 || letter == 85 || letter == 89){
			letter += 32;
		}
		switch(letter){
			case 'a':
				printf("%d: 'a'\n", i);
				break;
			case 'e':
				printf("%d: 'e'\n", i);
				break;
			case 'i':
				printf("%d: 'i'\n", i);
				break;
			case 'o':
				printf("%d: 'o'\n", i);
				break;
			case 'u':
				printf("%d: 'u'\n", i);
				break;
			case 'y':
				if(i > 2){	
					printf("%d: 'y'\n", i);
				}
				break;
			default:
				printf("%d: %c is not a vowel\n", i, letter);
		}
	}
	return 0;
}
