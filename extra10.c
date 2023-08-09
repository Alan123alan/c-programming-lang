#include <stdio.h>

int printer(char letter, int index)
{
	switch(letter){
		case 'a':
			printf("%d: 'a'\n", index);
			break;
		case 'e':
			printf("%d: 'e'\n", index);
			break;
		case 'i':
			printf("%d: 'i'\n", index);
			break;
		case 'o':
			printf("%d: 'o'\n", index);
			break;
		case 'u':
			printf("%d: 'u'\n", index);
			break;
		case 'y':
			if(index > 2){	
				printf("%d: 'y'\n", index);
			}
			break;
		default:
			printf("%d: %c is not a vowel\n", index, letter);
			return 1;
	}
	return 0;
}

char to_lower(char letter)
{
	if(letter == 65 || letter == 69 || letter == 73 || letter == 79 || letter == 85 || letter == 89){
		letter += 32;
	}
	return letter;
}

int main(int argc, char *argv[])
{
	if(argc != 2){
		printf("Error: You need one argument.\n");
		//this is how you abort a program
		return 1;
	}
	int i;
	char letter;
	//following the extra credit point 2 about initializing letter inside for loop
	//if you don't add duplicate code to update letter then for loop will keep executing
	//since it will keep the first letter from argv string which most probably isn't a \0 terminator
	//if you duplicate the initialization statement inside the loop as an updater you get another bug
	//you will print on empty char after whatever you input, thus breaking the printer
	//broken printer works like this
	//because the increment to i occurs after letter is updated inside the loop
	//the comparison is always to the previous letter to what will actually be printed
	//allowing the '\0' terminator to be printed
	for(i = 0, letter = argv[1][i]; letter != '\0'; i++){
		letter = to_lower(argv[1][i]);
		printer(letter, i);
	}
	//working printer
	for(i = 0; argv[1][i] != '\0'; i++){
		letter = to_lower(argv[1][i]);
		printer(letter, i);
	}	
	return 0;
}
