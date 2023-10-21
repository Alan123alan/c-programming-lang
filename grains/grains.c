#include <stdio.h>
#include <stdint.h>
#include <math.h>

uint64_t square(uint8_t index);
uint64_t total(void);

int main(int argc, char *argv[]){
    printf("grains at square 1 %llu.\n", square(1));
    printf("grains at square 2 %llu.\n", square(2));
    printf("grains at square 3 %llu.\n", square(3));
    printf("grains at square 4 %llu.\n", square(4));
    printf("grains at square 64 %llu.\n", square(64));
    printf("total grains %llu.\n", total());
}


uint64_t square(uint8_t index){
    return pow(2,index - 1);
}

//had to modify this total function in exercism to make it behave the same way as in my local
//why? some issue between stdints and int being mixed?
uint64_t total(void){
    uint64_t total = 0;
    //for was modified in exercism to
    //for(int i = 1; i <= 64; i++)
    for(int i = 0; i < 64; i++){
        total += pow(2,i);
        //line was modified in exercism to
        //total += square(i)
    }
    return total;
}
