#include <stdio.h>

int main(int argc, char *argv[])
{
	int x = 20;
	int y = 30;

	if(x>=y){
		printf("X:%d is greater than Y:%d.\n", x, y);
	}else if(x==y){
		printf("X:%d and Y:%d are equal.\n", x, y);
	}else{
		printf("X:%d is less than Y:%d.\n", x, y);
	}
	
	switch(x){
		case 20:
			printf("You are in switch statement branch x == 20.\n");
			break;
		default:
			printf("You are in switch statement branch default.\n");
			break;
	}
	
	while(x<25){
		x++;
	}
	printf("The value of X after the while loop is : %d.\n", x);

	do{
		x++;
	}while(x<25);

	printf("Even though X was 25 before the start of do while loop and the condition is x<25.\n");
	printf("Since a do while is executed at least once, X final value is %d.\n",x);
}
