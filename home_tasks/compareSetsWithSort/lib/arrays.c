#include <arrays.h>

int_duple_dynamic_array_t get_array_from_console() {
    printf("Enter multiset (e.g. \"<<1, 2>, <1>>\"): ");
    char *str_input = malloc(100 * sizeof(char));
    scanf("%s", str_input);

    int_duple_dynamic_array_t *array = malloc(sizeof(int_duple_dynamic_array_t));

    initialize_subarrays(str_input, array);

    free(str_input);

    return *array;
}

// Return point to subarray (int_dynamic_array_t) of int_duple_dynamic_array_t
int_dynamic_array_t *get_subarray(int_duple_dynamic_array_t *array, int index) {
    return &array->container[index];
}
