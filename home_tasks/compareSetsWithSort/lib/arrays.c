#include <arrays.h>

// Return point to subarray (int_dynamic_array_t) of int_duple_dynamic_array_t
int_dynamic_array_t *get_subarray(int_duple_dynamic_array_t *array, int index) {
    return &array->container[index];
}
