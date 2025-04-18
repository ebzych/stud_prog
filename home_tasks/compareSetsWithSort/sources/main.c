#include <compsets.h>
#include <arrays.h>
#include <simple_input.h>
#include <stdio.h>

int main() {
    // int_duple_dynamic_array_t arr1 = simply_get_from_console();
    // int_duple_dynamic_array_t arr2 = simply_get_from_console();

    int first_params[] = {2, 2, 2, 1, 1, 1};
    int second_params[] = {2, 1, 1, 2, 1, 2};
    int_duple_dynamic_array_t arr1 = create_DDarray_from_array(first_params);
    int_duple_dynamic_array_t arr2 = create_DDarray_from_array(second_params);

    printf("%i", multisets_are_equal(&arr1, &arr2));

    free_array(&arr1);
    free_array(&arr2);

    return 0;
}