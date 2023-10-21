#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <stdlib.h>

float square_root(unsigned int radicand){
    float approximation = (float)radicand;
    printf("Initial approximation for square root: %f.\n", approximation);
    float precission = pow(10, -10);
    printf("Precission for square root calculation: %f.\n", precission);
    while(fabs(radicand - (float)pow(approximation, 2)) > precission){
        approximation = (approximation + (float)radicand/approximation)/2.0;
    	printf("Approximation for square root: %f.\n", approximation);
    }
    return approximation;
}

int main(int argc, char *argv[]){
    printf("Square root approximation for radicand = 4 -> %f.\n", square_root(4));
}
