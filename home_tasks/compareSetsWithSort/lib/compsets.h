#ifndef COMPSETS
#define COMPSETS

#include <includes.h>
#include <arrays.h>

int comp_one_dim_array(const void *first, const void *second);
int comp_two_dim_array(const void *first_arr, const void *second_arr);
void sort_subarrays(int_duple_dynamic_array_t *array);
void sort_array(int_duple_dynamic_array_t *array);
bool multisets_are_equal(int_duple_dynamic_array_t * first,
    int_duple_dynamic_array_t * second);

#endif //COMPSETS