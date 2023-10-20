#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int hamming_distance(const char *lhs, const char *rhs);

int main(int argc, char *argv[]){
    printf("hamming_distance: %d.\n",hamming_distance("AATG", "AAA"));
    printf("hamming_distance: %d.\n",hamming_distance("", ""));
}

int hamming_distance(const char *lhs, const char *rhs){
    if(lhs == NULL || rhs == NULL)
        return -1;
    int lhs_len = strlen(lhs);
    int rhs_len = strlen(rhs);
    if(lhs_len == 0 && rhs_len == 0)
        return 0;
    if(lhs_len > rhs_len || lhs_len < rhs_len)
        return -1;
    int hamming_distance = 0;
    for(int i = 0; i < lhs_len; i++){
        if(lhs[i] != rhs[i])
            hamming_distance++;
    }
    return hamming_distance;
}
