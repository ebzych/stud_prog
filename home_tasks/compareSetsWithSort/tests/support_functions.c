#include "support_functions.h"
#include <stdlib.h>
#include <arrays.h>
#include <stdbool.h>

int_duple_dynamic_array_t *create_array() {
    int_duple_dynamic_array_t *arr;
    arr->size = 2;
    arr->container =
        malloc(arr->size * sizeof(int_duple_dynamic_array_t *));
    arr->container[0].size = 2;
    arr->container[0].container =
        malloc(arr->container[0].size * sizeof(int_dynamic_array_t *));
    arr->container[1].container =
        malloc(sizeof(int_dynamic_array_t *));
    arr->container[0].container[0] = 2;
    arr->container[0].container[1] = 1;
    arr->container[1].container[0] = 1;
    return arr;
}

// special comparator
int comp_int(const void* a, const void* b) {
    return *(int *)a < *(int *)b ? -1 : 1;
}

bool check_trivial_duple_array(int_duple_dynamic_array_t *array) {
    int arr[3];

    // add element to 'arr[]'
    int ind = 0;
    for (int i = 0; i < array->size; i++) {
        for (int j = 0; j < array->container[i].size; j++) {
            // check that '2' belong in subarray with size 2
            if (array->container[i].container[j] == 2) {
                if (array->container[i].size != 2) {
                    return false;
                }
            }

            arr[ind] = array->container[i].container[j];
            ind++;
        }
    }

    qsort(&arr, sizeof(arr) / sizeof(int), sizeof(int), comp_int);

    // compare content array
    int expected[] = { 1, 1, 2 };
    for (int i = 0; i < 3; i++) {
        if (arr[i] != expected[i])
            { return false; }
    }

    return true;
}