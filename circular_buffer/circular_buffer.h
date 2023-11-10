#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#include<stdint.h>
#include<stdlib.h>

typedef int buffer_value_t;

typedef struct {
    int16_t *inptr;
    int16_t *outptr;
    uint32_t capacity; 
} circular_buffer_t;

circular_buffer_t *new_circular_buffer(size_t capacity);

#endif
