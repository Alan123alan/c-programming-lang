#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

const int *binary_search(int value, const int *arr, size_t length);
const int *recursion(int value, const int *arr, size_t length, int upper_limit, int lower_limit);

int main(int argc, char *argv[]){
    int value = 5;
    const int value_after_mid[] = {1,3,4,5,8,9};
    printf("size of value_after_mid: %lu.\n", sizeof(value_after_mid)/sizeof(int));
    //const int *value_before_mid = [1,5,6,7,8,9];
    //const int *value_at_mid = [1,3,5,6,8,9];
    printf("searching %d in value_after_mid, got: %d.\n", value, *binary_search(5,value_after_mid,6));
    
}

const int *binary_search(int value, const int *arr, size_t length){
    //need to add the upper and lower limits to pass them as initializers for the recursion function 
    int lower_limit = 0;
    int upper_limit = length;
    return recursion(value, arr, length, upper_limit, lower_limit);
}

const int *recursion(int value, const int *arr, size_t length, int upper_limit, int lower_limit){
    if(arr == NULL)
        return NULL;
    //mid should be a pointer to a value at the middle of upper_limit and lower_limit pointers?
    //changed function signature to get limits as ints, this makes more sense for indexing on arr
    int mid = (upper_limit + lower_limit)/2;
    //using a pointer as index for a pointer makes sense? 
    if(arr[mid] == value)
        return &arr[mid];
    if(arr[mid] > value){
        upper_limit = mid - 1; 
        return recursion(value, arr, length, upper_limit, lower_limit);
    }
    if(arr[mid] < value){
        lower_limit = mid + 1;
        return recursion(value, arr, length, upper_limit, lower_limit);
    }
}
