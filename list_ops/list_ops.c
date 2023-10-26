#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int list_element_t;

typedef struct {
   size_t length;
   list_element_t elements[];
} list_t;

/*IMPLEMENTED*/

// constructs a new list
list_t *new_list(size_t length, list_element_t elements[]);
// append entries to a list and return the new list
list_t *append_list(list_t *list1, list_t *list2);
// filter list returning only values that satisfy the filter function
list_t *filter_list(list_t *list, bool (*filter)(list_element_t));
// returns the length of the list
size_t length_list(list_t *list);
// destroy the entire list
// list will be a dangling pointer after calling this method on it
void delete_list(list_t *list);
// prints elements in a list similar to how python does when printing lists
void print_list_elements(size_t length, list_element_t elements[]);
// a utility function to test filter
bool is_greater_than_2(list_element_t element);
// return a list of elements whose values equal the list value transformed by
// the mapping function
list_t *map_list(list_t *list, list_element_t (*map)(list_element_t));
// utility function to test map
list_element_t duplicate(list_element_t element);
// folds (reduces) the given list from the left with a function
list_element_t foldl_list(list_t *list, list_element_t initial, list_element_t (*foldl)(list_element_t, list_element_t));
//utility function to reduce a list by squaring it
list_element_t reduce_by_square(list_element_t accumulator, list_element_t element);
// folds (reduces) the given list from the right with a function
list_element_t foldr_list(list_t *list, list_element_t initial, list_element_t (*foldr)(list_element_t, list_element_t));
// reverse the elements of the list
list_t *reverse_list(list_t *list);


/*PENDING*/



int main(int argc, char *argv[]){
    list_element_t list1_elements[] = {0,1,2,3,4,5};
    list_element_t list2_elements[] = {6,7,8,9,10,11};
    list_t *list1 = new_list(6, list1_elements);
    list_t *list2 = new_list(6, list2_elements);
    printf("list1 length: %zu.\n", list1->length);
    print_list_elements(list1->length, list1->elements);
    printf("list2 length: %zu.\n", list2->length);
    print_list_elements(list2->length, list2->elements);
    list_t *combined_lists = append_list(list1, list2);
    printf("list1 and list 2 combined length: %zu.\n", combined_lists->length);
    print_list_elements(combined_lists->length, combined_lists->elements);

    list_t *empty_list1 = new_list(0, NULL);
    list_t *empty_list2 = new_list(0, NULL);
    list_t *combined_empty_lists = append_list(empty_list1, empty_list2);
    printf("empty lists combined length: %zu.\n", combined_empty_lists->length);
    print_list_elements(combined_empty_lists->length, combined_empty_lists->elements);
    
    list_t *filtered_list1 = filter_list(list1, is_greater_than_2);
    printf("filtered list1 length: %zu.\n", filtered_list1->length);
    print_list_elements(filtered_list1->length, filtered_list1->elements);
    
    list_t *mapped_list1 = map_list(list1, duplicate);
    printf("mapped list1 length: %zu.\n", mapped_list1->length);
    print_list_elements(mapped_list1->length, mapped_list1->elements);
    list_element_t reduce_l_result = foldl_list(list1, 0, reduce_by_square);
    printf("The result of left reducing list 1 with an initial value of 0 is: %d.\n", reduce_l_result);
    list_element_t reduce_r_result = foldr_list(list1, 0, reduce_by_square);
    printf("The result of rigth reducing list 1 with an initial value of 0 is: %d.\n", reduce_r_result);
    list_t *reversed_list1 = reverse_list(list1);
    print_list_elements(reversed_list1->length, reversed_list1->elements);
  
    list_t *empty_list = new_list(0, NULL);
    printf("empty_list size should be 8 bytes? 4 bytes for the size_t type and 4 bytes for the char pointer : %lu.\n", sizeof(empty_list));
    printf("Bytes for the size_t type: %lu.\n", sizeof(empty_list->length));
    printf("elements point to:  %d.\n", *(empty_list->elements));
    printf("elements point to something equal to null:  %d.\n", *(empty_list->elements) == NULL);
    delete_list(list1);
    delete_list(list2);
    delete_list(combined_lists);
    delete_list(filtered_list1);
    delete_list(mapped_list1);
    delete_list(reversed_list1);
}

list_element_t duplicate(list_element_t element){
    return element*2;
}

list_element_t reduce_by_square(list_element_t accumulator, list_element_t element){
    accumulator += element*element;
    return accumulator;
}

bool is_greater_than_2(list_element_t element){
	return element > 2;
}

void print_list_elements(size_t length, list_element_t elements[]){
    for(int i = 0; i < (int)length; i++){
        printf("%d\t", elements[i]);
    }
    printf("\n");
}


list_t *new_list(size_t length, list_element_t elements[]){
    //How to allocate memory for a struct that includes a flexible array?
    //dynamically allocate enough memory for the struct + the calculated length of the array
    //adding a case for when length is == 0
    if(length == 0){
        list_t *empty_list = malloc(sizeof(list_t));
        if(empty_list == NULL){
            perror("Memory allocation for list_t failed.\n");
            exit(EXIT_FAILURE);
        }
        empty_list->length = 0;
        return empty_list;
    }
    list_t *new_list = malloc(sizeof(list_t) + (sizeof(list_element_t)*length));
    if(new_list == NULL){
        perror("Memory allocation for list_t failed.\n");
        exit(EXIT_FAILURE);
    }
    new_list->length = length;
    for(int i = 0; i < (int)length; i++){
        new_list->elements[i] = elements[i];
    }
    return new_list;
}

void delete_list(list_t *list){
    free(list);
}

list_t *append_list(list_t *list1, list_t *list2){
    if(list1 == NULL || list2 == NULL){
        perror("One of the list_t to be appended is NULL.\n");
        return NULL;
    }
    size_t total_length = list1->length + list2->length;
    if(total_length == 0){
        return new_list(total_length, NULL);
    }
    list_t *new_list = malloc(sizeof(list_t) + (sizeof(list_element_t) * total_length));
    if(new_list == NULL){
        perror("Memory allocation for list_t failed.\n");
        exit(EXIT_FAILURE);
    }
    new_list->length = total_length;
    int i = 0;
    while(i < (int)list1->length){
       new_list->elements[i] = list1->elements[i]; 
       i++;
    }
    while(i < (int)total_length){
       new_list->elements[i] = list2->elements[i-(int)list1->length]; 
       i++;
    }
    return new_list;
}

size_t length_list(list_t *list){
    return list->length;
}

//I didn't know you could pass functions to another functions in C
list_t *filter_list(list_t *list, bool (*filter)(list_element_t)){
    //should this function do a previous loop to count the elements that
    //pass the filter? so we can allocate just enough memory?
    list_t *filtered_list = malloc(sizeof(list_t));
    filtered_list->length = 0;
    int j = 0;
    for(int i = 0; i < (int)list->length; i++){
        if(filter(list->elements[i])){
            filtered_list->elements[j] = list->elements[i];
            filtered_list->length++;
            j++;
        }
    }
    return filtered_list;
}

list_t *map_list(list_t *list, list_element_t (*map)(list_element_t)){
    //a mapped list maintains it's size so using size of original list should be fine
    list_t *mapped_list = malloc(sizeof(list_t) + (sizeof(list_element_t)*list->length));
    mapped_list->length = list->length;
    for(int i = 0; i < (int)list->length; i++){
        list_element_t temp = list->elements[i];
        mapped_list->elements[i] = map(temp);
    }
    return mapped_list;
}

list_element_t foldl_list(list_t *list,list_element_t initial, list_element_t (*reducer)(list_element_t, list_element_t)){
    list_element_t accumulator =  initial;
    for(int i = 0; i < (int)list->length; i++){
        accumulator = reducer(accumulator, list->elements[i]);
    }
    return accumulator;
}

list_element_t foldr_list(list_t *list,list_element_t initial, list_element_t (*reducer)(list_element_t, list_element_t)){
    list_element_t accumulator =  initial;
    for(int i = ((int)list->length)-1; i >= 0; i--){
        accumulator = reducer(accumulator, list->elements[i]);
    }
    return accumulator;
}


list_t *reverse_list(list_t *list){
    list_t *reversed_list = malloc(sizeof(list_t) + (sizeof(list_element_t)*list->length));
    reversed_list->length = list->length;
    for(int i = (int)reversed_list->length - 1; i >= 0; i--){
	printf("element %d at indx %d in original list maps to indx %lu in reversed list.\n", list->elements[i], i, (reversed_list->length - i));
        reversed_list->elements[(reversed_list->length-1) - i] = list->elements[i]; 
    }
    return reversed_list;
}
