#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#include<stdint.h>

typedef int buffer_value_t;

typedef struct {
    buffer_value_t values[];
    uint32_t capacity; 
} circular_buffer_t;

#endif
