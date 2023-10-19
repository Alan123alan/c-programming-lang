#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

int power(int base, int power);
int *get_digits(int number, int digit_count);
int get_digit_count(int number);
bool is_armstrong_number(int candidate);

int main(int argc, char **argv){
	printf("%d.\n", is_armstrong_number(5));
	printf("%d.\n", is_armstrong_number(10));
	printf("%d.\n", is_armstrong_number(153));
	printf("%d.\n", is_armstrong_number(100));
}

bool is_armstrong_number(int candidate){
    int digit_count = get_digit_count(candidate);
    printf("digit_count: %d.\n", digit_count);
    int *digits = get_digits(candidate, digit_count);
    printf("digits: %p.\n", digits);
    int total = 0;
    for(int i = 0; i < digit_count; i++){
        total +=  power(digits[i], digit_count);
    }
    printf("total: %d.\n", total);
    printf("candidate: %d | total: %d\n", candidate, total);
    if(candidate == total)
        return true;
    return false;
}

int power(int base, int power){
    if(power == 0)
        return 1;
    int total = 1;
    for(int i = 0; i < power; i++){
        total *= base;
    } 
    return total;
}

int *get_digits(int number, int digit_count){
    int *digits;
    digits = malloc(digit_count * sizeof(int));
    for(int i = 0; i < digit_count; i++){
        int digit = number % 10;
	printf("digit: %d.\n", digit);
        number = number / 10;
        digits[i] = digit;
    }
    return digits;
}

int get_digit_count(int number){
    int count = 0;
    while(number != 0){
        number = number / 10;
        count++;
    }
    return count;
}
