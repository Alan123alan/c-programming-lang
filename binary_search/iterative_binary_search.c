#include <stdio.h>
#include <stddef.h>

const int *binary_search(int value, const int *arr, size_t length);

int main(int argc, char *argv[]){
   int value = 6;
   int arr[] = { 1, 3, 4, 6, 8, 9, 11 };
   size_t length = sizeof(arr) / sizeof(arr[0]);
   printf("Binary searching %d in array: %d.\n", value, *binary_search(value, arr, length));
}

const int *binary_search(int value, const int *arr, size_t length){
    if(arr == NULL)
        return NULL;
    if(length == 0)
        return NULL;
    //need to add the upper and lower limits to pass them as initializers for the iterative search 
    int lower_limit = 0;
    int upper_limit = length;
    int mid = (upper_limit + lower_limit)/2;
    while(lower_limit <= upper_limit){
        mid = (upper_limit + lower_limit)/2;
        if(arr[mid] > value){
            upper_limit = mid - 1;
        }else if(arr[mid] < value){
            lower_limit = mid + 1;
        }else{
            return &arr[mid];
        }
    }
    return NULL;
}
