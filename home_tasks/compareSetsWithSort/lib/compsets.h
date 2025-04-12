#ifndef COMPSETS
#define COMPSETS

#include <includes.h>
#include <arrays.h>

int comp_one_dim_array(const void *first, const void *second);
bool multisets_are_equal(int_duple_dynamic_array_t * first,
    int_duple_dynamic_array_t * second);

#endif //COMPSETS