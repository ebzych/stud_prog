#include "dynamic_arr_hashset_lib.h"

array_hashset_t *create_hashset(size_t h_size) {
    array_hashset_t *hashset_p = malloc(sizeof(array_hashset_t));
    hashset_p->size = h_size;
    hashset_p->inner_sizes = malloc(hashset_p->size * sizeof(int));
    hashset_p->container = malloc(sizeof(int_dynamic_array_t *));

    if (initialize_hashset(hashset_p) != SUCCESS)
        { hashset_p = NULL; };   // if errors occurred in initializing

    return hashset_p;
};

enum hashset_returns initialize_hashset(array_hashset_t *hashset) {
    if (hashset == NULL) { return NULL_PTR; }

    hashset->container =
        malloc(hashset->size * sizeof(int_dynamic_array_t *)); // allocate container

    if (hashset->container == NULL) { return MEM_NOT_ALLOC; }    // check if memory is not allocated

    for (int i = 0; i < hashset->size; i++) {
        hashset->container[i] =
            malloc(STANDARD_BUCKET_SIZE * sizeof(int_dynamic_array_t)); // allocate buckets with standard size

        for (int j = 0; j < STANDARD_BUCKET_SIZE; j++) {
            hashset->container[i][j] = malloc(sizeof(int_dynamic_array_t *));
            if (hashset->container[i][j] == NULL) { return MEM_NOT_ALLOC; }    // check if memory is not allocated
        }

        if (hashset->container[i] == NULL) { return MEM_NOT_ALLOC; }    // check if memory is not allocated
    }

    return SUCCESS;
}

enum hashset_returns hashset_resize(array_hashset_t *hashset) {
    array_hashset_t *new_hashset = create_hashset(hashset->size * 2);

    for (int i = 0; i < hashset->size; i++) {
        for (int j = 0; j < hashset->inner_sizes[i]; j++) {
            if (hashset_add(new_hashset, hashset->container[i][j]) == MEM_NOT_ALLOC)
                { return MEM_NOT_ALLOC; };
        }

        free(hashset->container[i]);
    }

    free(hashset->inner_sizes);
    free(hashset);

    return SUCCESS;
}

enum hashset_returns hashset_add(array_hashset_t *hashset, int_dynamic_array_t *new_array) {
    if (hashset == NULL) { return NULL_PTR; }

    int index_of_bucket = get_array_hashcode(new_array) % hashset->size;
    int last_in_bucket = hashset->inner_sizes[index_of_bucket];

    hashset->container[index_of_bucket][last_in_bucket] = new_array;
    hashset->inner_sizes[index_of_bucket]++;

    if (hashset->inner_sizes[index_of_bucket] == STANDARD_BUCKET_SIZE) {
        if (hashset_resize(hashset) == MEM_NOT_ALLOC)
            { return MEM_NOT_ALLOC; };
    }

    return SUCCESS;
}

// get hash of (int *)array: multiply all elements divide number of elements
unsigned long get_array_hashcode(int_dynamic_array_t *array) {
    unsigned long hash = 1;
    unsigned long sum = 0;
    for (int i = 0; i < array->size; i++) {
        hash *= array->arr[i];
        sum += array->arr[i];
    }

    return array->size != 0 ?
        (unsigned long)((hash + sum) / array->size)
        : 0;
}
