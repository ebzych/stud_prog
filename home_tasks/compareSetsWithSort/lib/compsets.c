#include <compsets.h>

int comp_one_dim_array(void *first, void *second) {
    if (first == second) {
        return 0;
    }
    if (first > second) {
        return 1;
    }
    if (first < second) {
        return -1;
    }
}

extern __compar_fn_t (*ptr) (void *, void *) = comp_one_dim_array;

bool multisets_is_equal(const int_duple_dynamic_array_t * const first,
        const int_duple_dynamic_array_t * const second) {
    // check for null, empty size
    if (first->size != second->size)
        { return false; }

    for (int i = 0; i < first->size; i++) {
        size_t size = first->container[i].size;
        int_dynamic_array_t *array = &first->container[i];
        qsort(array->container, size, size * sizeof(int_dynamic_array_t), ptr);
    }

    return true;
}
