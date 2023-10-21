#include <stdio.h>
#include <stdint.h>
#include <math.h>

unsigned int sum_of_squares(unsigned int number);
unsigned int square_of_sum(unsigned int number);
unsigned int difference_of_squares(unsigned int number);


int main(int argc, char *argv[]){
    printf("sum of squares: %u.\n", sum_of_squares(10));
    printf("square of sums: %u.\n", square_of_sum(10));
    printf("sum of squares: %u.\n", difference_of_squares(10));
}

unsigned int sum_of_squares(unsigned int number){
    unsigned int sum = 0;
    for(unsigned int n = 1; n <= number; n++){
       sum += pow(n, 2); 
    }
    return sum;
}

unsigned int square_of_sum(unsigned int number){
    unsigned int sum = 0;
    for(unsigned int n = 1; n <= number; n++){
       sum += n; 
    }
    return pow(sum, 2);
}

unsigned int difference_of_squares(unsigned int number){
    return square_of_sum(number) - sum_of_squares(number);
}
