#ifndef LIST_OPS_H
#define LIST_OPS_H

#include <stdlib.h>
#include <stdio.h>
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
list_t *map_list(list_t *list, list_element_t (*map)(list_element_t));

// folds (reduces) the given list from the left with a function
list_element_t foldl_list(list_t *list, list_element_t initial, list_element_t (*foldl)(list_element_t, list_element_t));

// folds (reduces) the given list from the right with a function
list_element_t foldr_list(list_t *list, list_element_t initial, list_element_t (*foldr)(list_element_t, list_element_t));

// reverse the elements of the list
list_t *reverse_list(list_t *list);

// destroy the entire list
// list will be a dangling pointer after calling this method on it
void delete_list(list_t *list);

// prints elements in a list similar to how python does when printing lists
void print_list(size_t length, list_element_t elements[]);

// a utility function to test filter by only allowing elements greater than two in the list
bool is_greater_than_2(list_element_t element);

// utility function to test map by multiplying all elements in the list by two
list_element_t duplicate(list_element_t element);

//utility function to reduce a list by squaring al it's elements and accumulating them
list_element_t reduce_by_square(list_element_t accumulator, list_element_t element);

#endif

