#include <stdio.h>

int main(int argc, char *argv[])
{
	int i = 0;
	while(i < 25){
		printf("Loop is currently at iteration #%d.\n", i);
		i++;
	}
	//adding backwards while loop count
	while(i >= 0){
		printf("Loop is currently at iteration #%d.\n", i);
		i--;
	}
	return 0;
}
