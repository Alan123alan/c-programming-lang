#include "list_ops.h"

// int main(int argc, char *argv[]){
//     list_element_t list1_elements[] = {0,1,2,3,4,5};
//     list_element_t list2_elements[] = {6,7,8,9,10,11};
//     list_t *list1 = new_list(6, list1_elements);
//     list_t *list2 = new_list(6, list2_elements);
//     printf("list1:\n");
//     print_list(list1->length, list1->elements);
//     printf("list2:\n");
//     print_list(list2->length, list2->elements);
//     list_t *combined_lists = append_list(list1, list2);
//     printf("combined_lists:\n");
//     print_list(combined_lists->length, combined_lists->elements);

//     list_t *empty_list1 = new_list(0, NULL);
//     list_t *empty_list2 = new_list(0, NULL);
//     list_t *combined_empty_lists = append_list(empty_list1, empty_list2);
//     printf("combined_empty_lists:\n");
//     print_list(combined_empty_lists->length, combined_empty_lists->elements);
    
//     list_t *filtered_list1 = filter_list(list1, is_greater_than_2);
//     printf("filtered_list1:\n");
//     print_list(filtered_list1->length, filtered_list1->elements);
    
//     list_t *mapped_list1 = map_list(list1, duplicate);
//     printf("mapped_list1:\n");
//     print_list(mapped_list1->length, mapped_list1->elements);
//     list_element_t reduce_l_result = foldl_list(list1, 0, reduce_by_square);
//     printf("reduce_l_result: %d.\n", reduce_l_result);
//     list_element_t reduce_r_result = foldr_list(list1, 0, reduce_by_square);
//     printf("reduce_r_result: %d.\n", reduce_r_result);
//     list_t *reversed_list1 = reverse_list(list1);
//     printf("reversed_list1:\n");
//     print_list(reversed_list1->length, reversed_list1->elements);
  
//     delete_list(list1);
//     delete_list(list2);
//     delete_list(empty_list1);
//     delete_list(empty_list2);
//     delete_list(combined_lists);
//     delete_list(combined_empty_lists);
//     delete_list(filtered_list1);
//     delete_list(mapped_list1);
//     delete_list(reversed_list1);
// }

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

void print_list(size_t length, list_element_t elements[]){
    printf("Elements -> [");
    for(int i = 0; i < (int)length; i++){
        printf("%d", elements[i]);
        if(i < ((int)length - 1)){
            printf(", ");
        }
    }
    printf("]");
    printf("\n");
    printf("Length -> %lu\n", length);
    printf("\n");
}

// list_t is_empty_list(list_t * list){
//     if(list->length == 0){
//         list_t *empty_list = malloc(sizeof(list_t));
//         if(empty_list == NULL){
//             perror("Memory allocation for list_t failed");
//             exit(EXIT_FAILURE);
//         }
//         empty_list->length = 0;
//     return empty_list;
//     }
// }


list_t *new_list(size_t length, list_element_t elements[]){
    list_t *new_list = malloc(sizeof(list_t) + (sizeof(list_element_t)*length));
    if(new_list == NULL){
        perror("Memory allocation for list_t failed.\n");
        exit(EXIT_FAILURE);
    }
    new_list->length = length;
    for(size_t i = 0; i < length; i++){
        new_list->elements[i] = elements[i];
    }
    return new_list;
}

void delete_list(list_t *list){
    free(list);
}

list_t *append_list(list_t *list1, list_t *list2){
    // if(list1 == NULL || list2 == NULL){
    //     perror("One of the list_t to be appended is NULL.\n");
    //     return NULL;
    // }
    size_t total_length = list1->length + list2->length;
    
    // if(total_length == 0){
    //     return new_list(total_length, NULL);
    // }
    list_t *combined_list = malloc(sizeof(list_t) + (sizeof(list_element_t) * total_length));
    // list_t *combined_list = new_list(total_length, NULL); 
    if(combined_list == NULL){
        perror("Memory allocation for list_t failed.\n");
        exit(EXIT_FAILURE);
    }
    size_t i = 0;
    while(i < list1->length){
       combined_list->elements[i] = list1->elements[i]; 
       i++;
    }
    while(i < total_length){
       combined_list->elements[i] = list2->elements[i-list1->length]; 
       i++;
    }
    combined_list->length = total_length;
    
    return combined_list;
}

size_t length_list(list_t *list){
    return list->length;
}

list_t *filter_list(list_t *list, bool (*filter)(list_element_t)){
    //should this function do a previous loop to count the elements that
    //pass the filter? so we can allocate just enough memory?
    //issue was that filter function was missmanaging memory by creating a struct that
    //didn't allocated any memory for the elements array :(
    list_t *filtered_list = new_list(list->length, list->elements);
    int j = 0;
    for(int i = 0; i < (int)list->length; i++){
        if(filter(list->elements[i])){
            filtered_list->elements[j] = list->elements[i];
            j++;
        }
    }
    filtered_list->length = j;
    return filtered_list;
}

list_t *map_list(list_t *list, list_element_t (*map)(list_element_t)){
    list_t *mapped_list = new_list(list->length, list->elements);
    mapped_list->length = list->length;
    for(size_t i = 0; i < list->length; i++){
        mapped_list->elements[i] = map(list->elements[i]);
    }
    return mapped_list;
}

list_element_t foldl_list(list_t *list,list_element_t initial, list_element_t (*reducer)(list_element_t, list_element_t)){
    list_element_t accumulator =  initial;
    for(int i = 0; i < (int)list->length; i++){
        // accumulator = reducer(accumulator, list->elements[i]);
        accumulator = reducer(list->elements[i], accumulator);
    }
    return accumulator;
}

list_element_t foldr_list(list_t *list,list_element_t initial, list_element_t (*reducer)(list_element_t, list_element_t)){
    list_element_t accumulator =  initial;
    for(int i = ((int)list->length)-1; i >= 0; i--){
        accumulator = reducer(list->elements[i], accumulator);
    }
    return accumulator;
}


list_t *reverse_list(list_t *list){
    if(list->length == 0){
        return new_list(0, NULL);
    }
    list_t *reversed_list = malloc(sizeof(list_t) + (sizeof(list_element_t)*list->length));
    if(reversed_list == NULL){
            perror("Memory allocation for list_t failed");
            exit(EXIT_FAILURE);
    }
    reversed_list->length = list->length;
    for(int i = (int)reversed_list->length - 1; i >= 0; i--){
        reversed_list->elements[(reversed_list->length-1) - i] = list->elements[i]; 
    }
    return reversed_list;
}
