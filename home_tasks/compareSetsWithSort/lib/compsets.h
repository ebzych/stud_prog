#ifndef COMPSETS
#define COMPSETS

#include <stdio.h>
#include <memory.h>

typedef int * int_array_t;

typedef struct int_dynamic_array {  // one-dimension dynamic array of int with size
    size_t size;
    int_array_t arr;   // (int *)container with int 
} int_dynamic_array_t;

typedef struct int_duple_dynamic_array {    // two-dimension dynamic array of int with size
    size_t size;
    int_dynamic_array_t *container;   // (int **)container of one-dimension dynamic arrays of int with size
} int_duple_dynamic_array_t;

#endif