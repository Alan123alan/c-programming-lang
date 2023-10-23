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
//list_t *filter_list(list_t *list, bool (*filter)(list_element_t));

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


int main(int argc, char *argv[]){
    list_element_t list1_elements[] = {0,1,2,3,4,5};
    list_element_t list2_elements[] = {6,7,8,9,10,11};
    list_t *list1 = new_list(6, list1_elements);
    list_t *list2 = new_list(6, list2_elements);
    printf("list1 length: %zu.\n", list1->length);
    printf("list2 length: %zu.\n", list2->length);
    delete_list(list1);
    delete_list(list2);
}


list_t *new_list(size_t length, list_element_t elements[]){
    list_t *new_list = malloc(sizeof(list_t));
    new_list->length = length;
    for(int i = 0; i < (int)length; i++){
        new_list->elements[i] = elements[i];
    }
    return new_list;
}

void delete_list(list_t *list){
    free(list->elements);
    free(list);
}

list_t *append_list(list_t *list1, list_t *list2){
    list_t *new_list = malloc(sizeof(list_t));
    new_list->length = list1->length + list2->length;
    list_element_t *new_elements = malloc(sizeof(list_element_t)*(new_list->length));
    for(int i = 0; i < (int)list1->length; i++){
       new_elements[i] = list1->elements[i]; 
    }
    for(int j = (int)list1->length; j < (int)new_list->length; j++){
       new_elements[j] = list2->elements[j]; 
    }
    return new_list;
}

size_t length_list(list_t *list){
    return list->length;
}
