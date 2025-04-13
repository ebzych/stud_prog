#include <arrays.h>
#include <stdlib.h>
#include <stdio.h>

// Return point to subarray (int_dynamic_array_t) of int_duple_dynamic_array_t
int_dynamic_array_t *get_subarray(int_duple_dynamic_array_t *array, int index) {
    return &array->container[index];
}

void print_array(int_duple_dynamic_array_t *arr) {
    for (int i = 0; i < arr->size; i++) {
        for (int j = 0; j < get_subarray(arr, i)->size; j++) {
            printf("%i ", get_subarray(arr, i)->container[j]);
        }

        printf("\n");
    }
}

void allocate_array(int_duple_dynamic_array_t *array) {
    array->container = malloc(array->size * sizeof(int_dynamic_array_t));
}

void allocate_subarray(int_dynamic_array_t *array) {
    array->container = malloc(array->size * sizeof(int_array_t));
}

int free_array(int_duple_dynamic_array_t *array) {
    for (int i = 0; i < array->size; i++) {
        free(get_subarray(array, i)->container);
    }

    free(array->container);
}
