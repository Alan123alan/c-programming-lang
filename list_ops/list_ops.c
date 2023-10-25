#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int list_element_t;

typedef struct {
   size_t length;
   list_element_t elements[];
} list_t;

// constructs a new list
list_t *new_list(size_t length, list_element_t elements[]);
// append entries to a list and return the new list
list_t *append_list(list_t *list1, list_t *list2);
// filter list returning only values that satisfy the filter function
list_t *filter_list(list_t *list, bool (*filter)(list_element_t));
// returns the length of the list
size_t length_list(list_t *list);
// return a list of elements whose values equal the list value transformed by
// the mapping function
//list_t *map_list(list_t *list, list_element_t (*map)(list_element_t));
// folds (reduces) the given list from the left with a function
//list_element_t foldl_list(list_t *list, list_element_t initial,
//                          list_element_t (*foldl)(list_element_t,
//                                                  list_element_t));
// folds (reduces) the given list from the right with a function
//list_element_t foldr_list(list_t *list, list_element_t initial,
//                          list_element_t (*foldr)(list_element_t,
//                                                  list_element_t));
// reverse the elements of the list
//list_t *reverse_list(list_t *list);
// destroy the entire list
// list will be a dangling pointer after calling this method on it
void delete_list(list_t *list);
// prints elements in a list similar to how python does when printing lists
void print_list_elements(size_t length, list_element_t elements[]);
// a utility function to test print
bool is_greater_than_2(list_element_t element);


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
    
    list_t *filtered_list1 = filter_list(list1, is_greater_than_2);
    printf("filtered list1 length: %zu.\n", filtered_list1->length);
    print_list_elements(filtered_list1->length, filtered_list1->elements);
    delete_list(list1);
    delete_list(list2);
    delete_list(combined_lists);
    delete_list(filtered_list1);
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
    list_t *new_list = malloc(sizeof(list_t) + (sizeof(list_element_t)*length));
    //confirming size of new_list struct, expected to be 28?
    printf("%lu.\n", sizeof(new_list));
    new_list->length = length;
    for(int i = 0; i < (int)length; i++){
        printf("%d\t|", elements[i]);
        new_list->elements[i] = elements[i];
        printf("%d\t|", new_list->elements[i]);
    }
    printf("\n");
    return new_list;
}

void delete_list(list_t *list){
    free(list);
}

list_t *append_list(list_t *list1, list_t *list2){
    size_t total_length = list1->length + list2->length;
    list_t *new_list = malloc(sizeof(list_t) + (sizeof(list_element_t) * total_length));
    new_list->length = total_length;
    //can I skip temp list memory allocation as in the new_list function?
    //list_element_t *new_elements = malloc(sizeof(list_element_t)*(new_list->length));
    //yes and no, you need to account for the array size in the struct
    for(int i = 0; i < (int)list1->length; i++){
       new_list->elements[i] = list1->elements[i]; 
    }
    for(int j = (int)list1->length; j < (int)new_list->length; j++){
       new_list->elements[j] = list2->elements[j-(int)list1->length]; 
    }
    return new_list;
}

size_t length_list(list_t *list){
    return list->length;
}

//I didn't know you could pass functions to another functions in C
list_t *filter_list(list_t *list, bool (*filter)(list_element_t)){
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
