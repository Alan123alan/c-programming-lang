#include "square_root.h"

uint16_t square_root(uint16_t radicand){
    float approximation = (float)radicand;
    float precission = pow(10, -10);
    while(fabs(radicand - (float)pow(approximation, 2)) > precission){
        approximation = (approximation + (float)radicand/approximation)/2.0;
    }
    return (uint16_t)approximation;
}
