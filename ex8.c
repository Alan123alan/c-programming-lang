#include <stdio.h>

int main(int argc, char *argv[])
{
	int i = 0;
	if(argc == 1){
		printf("You only have one argument.\n");
		printf("That argument is %s.\n", argv[0]);
	}else if(argc > 1 && argc < 4){
		printf("Arguments passed:\n");
		for(i=0;i<argc;i++){
			printf("Argument #%d is %s.\n", i, argv[i]);
		}
	}else{
		printf("You have too many arguments.\n");
	} 
	return 0;
}
