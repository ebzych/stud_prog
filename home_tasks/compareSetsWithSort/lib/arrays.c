#include <arrays.h>

// Return point to subarray (int_dynamic_array_t) of int_duple_dynamic_array_t
int_dynamic_array_t *get_subarray(int_duple_dynamic_array_t *array, int index) {
    return &array->container[index];
}

void print_array(int_duple_dynamic_array_t *arr) {
    for (int i = 0; i < arr->size; i++) {
        for (int j = 0; j < arr->container[i].size; j++) {
            printf("%i ", arr->container[i].container[j]);
        }

        printf("\n");
    }
}

