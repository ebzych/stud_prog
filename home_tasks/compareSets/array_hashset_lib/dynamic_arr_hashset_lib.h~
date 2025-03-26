#ifndef DYNAMIC_ARRAYS_HASHSET
#define DYNAMIC_ARRAYS_HASHSET

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define STANDARD_HASHSET_SIZE 6 // use for size of hashset
#define STANDARD_BUCKET_SIZE 3 // use for size of buckets in hashset

typedef int * int_array_t;

typedef struct int_dynamic_array {  // one-dimension dynamic array of int with size
    size_t size;
    int_array_t arr;   // (int *)container with int 
} int_dynamic_array_t;

typedef struct int_duple_dynamic_array {    // two-dimension dynamic array of int with size
    size_t size;
    int_dynamic_array_t *container;   // (int **)container of one-dimension dynamic arrays of int with size
} int_duple_dynamic_array_t;

typedef struct array_hashset {
    size_t size;   // number of buckets
    int_array_t inner_sizes;    // array of buckets sizes
    int_dynamic_array_t ***container;   // array of buckets with pointers to int_dynamic_array
} array_hashset_t;

enum hashset_returns {
    RESIZE_FAILURE = -3,
    NULL_PTR = -2,
    MEM_NOT_ALLOC = -1,
    SUCCESS = 0,
};

unsigned long get_array_hashcode(int_dynamic_array_t *array);
array_hashset_t *create_hashset();
enum hashset_returns initialize_hashset(array_hashset_t *hashset);
enum hashset_returns hashset_resize();
enum hashset_returns hashset_add(array_hashset_t *hashset, int_dynamic_array_t *new_array);

#endif