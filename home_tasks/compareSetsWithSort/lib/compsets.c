#include <compsets.h>

int comp_one_dim_array(const void *first_num, const void *second_num) {
    int *first = (int *)first_num;
    int *second = (int *)second_num;
    return *first < *second ?
            -1 : (*first > *second ? 1 : 0);
}

int comp_two_dim_array(const void *first_arr, const void *second_arr) {
    int i = 0;
    const int_dynamic_array_t *first = first_arr;
    const int_dynamic_array_t *second = second_arr;
    while (i < first->size && i < second->size &&
            first->container[i] == second->container[i])
        { i++; }

    if (first->container[i] < second->container[i]) {
        return -1;
    }

    if (first->container[i] == second->container[i]) {
        return first->size < second->size ?
                -1 : (first->size > second->size ? 1 : 0) ;
    }

    if (first->container[i] > second->container[i]) {
        return 1;
    }
}

void sort_subarrays(int_duple_dynamic_array_t *array) {
    for (int i = 0; i < array->size; i++) {
        size_t size = array->container[i].size;
        int_dynamic_array_t *arr = &array->container[i];
        qsort(arr->container, size, sizeof(int), comp_one_dim_array);
    }
}

void sort_array(int_duple_dynamic_array_t *array) {
    qsort(array->container, array->size, sizeof(int_dynamic_array_t), comp_two_dim_array);
}

bool multisets_are_equal(int_duple_dynamic_array_t * first,
        int_duple_dynamic_array_t * second) {
    // check for null, empty size
    if (first->size != second->size)
        { return false; }

    sort_subarrays(first);
    sort_subarrays(second);

    sort_array(first);
    sort_array(second);

    for (int i = 0; i < first->size; i++) {
        if (first->container[i].size != second->container[i].size)
            { return false; }

        for (int j = 0; j < first->container[i].size; j++) {
            int_array_t arr1 = first->container[i].container;
            int_array_t arr2 = second->container[i].container;
            if (arr1[j] != arr2[j])
                { return false; }
        }
    }

    return true;
}
