#ifndef ARRAYS
#define ARRAYS

typedef int * int_array_t;

typedef struct int_dynamic_array {  // one-dimension dynamic array of int with size
    size_t size;
    int_array_t container;   // (int *)container with int 
} int_dynamic_array_t;

typedef struct int_duple_dynamic_array {    // two-dimension dynamic array of int with size
    size_t size;
    int_dynamic_array_t *container;   // (int **)container of one-dimension dynamic arrays of int with size
} int_duple_dynamic_array_t;

int_dynamic_array_t *get_subarray(int_duple_dynamic_array_t *array, int index);
void print_array(int_duple_dynamic_array_t *arr);
void allocate_array(int_duple_dynamic_array_t *array);
void allocate_subarray(int_dynamic_array_t *array);
int free_array(int_duple_dynamic_array_t *array);

#endif //ARRAYS