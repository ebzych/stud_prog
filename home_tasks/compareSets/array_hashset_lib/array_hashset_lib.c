#include "dynamic_arr_hashset_lib.h"

array_hashset_t *create_hashset(size_t h_size) {
    array_hashset_t *hashset_p = malloc(sizeof(array_hashset_t));
    hashset_p->size = h_size;

    if (initialize_hashset(hashset_p) != SUCCESS)
        { hashset_p = NULL; };   // if errors occurred in initializing

    return hashset_p;
};

enum hashset_returns initialize_hashset(array_hashset_t *hashset) {
    if (hashset == NULL) { return NULL_PTR; }

    hashset->container =
        malloc(hashset->size * sizeof(bucket_t *)); // allocate container

    if (hashset->container == NULL)
        { return MEM_NOT_ALLOC; }    // check if memory is not allocated

    for (int i = 0; i < hashset->size; i++) {
        hashset->container[i] =
            malloc(sizeof(bucket_t)); // allocate buckets
            
        for (int j = 0; j < STANDARD_BUCKET_SIZE; j++) {
            pair_t *h_element = hashset->container[i]->pairs[j];
            hashset->container[i]->pairs[j]->count = 0; // start count of arrays is 0

            if ( (h_element->arr =                              // allocate elements of hashset
                malloc(sizeof(int_dynamic_array_t))) == NULL)   // and check memory is allocated
                { return MEM_NOT_ALLOC; }

            if ( (h_element->arr->arr =
                malloc(h_element->arr->size * sizeof(int_dynamic_array_t)))
                    == NULL )
                    { return MEM_NOT_ALLOC; }   // allocate and check dynamic array in pair
        }

        if (hashset->container[i] == NULL)
            { return MEM_NOT_ALLOC; }    // check if memory is not allocated
    }

    return SUCCESS;
}

void int_dyn_arr_free(int_dynamic_array_t *arr) {
    free(arr->arr);
    free(arr);
}

void pair_free(pair_t *pair) {
    int_dyn_arr_free(pair->arr);
    free(pair);
}

void bucket_free(bucket_t *bucket) {
    for (int i = 0; i < bucket->count; i++) {
        pair_free(bucket->pairs[i]);
    }

    free(bucket);
}

void hashset_free(array_hashset_t *hashset) {
    for (int i = 0; i < hashset->size; i++) {
        bucket_free(hashset->container[i]);
    }

    free(hashset);
}

bool dyn_arr_are_equivalent
    (int_dynamic_array_t *arr1, int_dynamic_array_t *arr2)
{
    if (arr1->size != arr2->size)
        { return false; }

    for (int i = 0; i < arr1->size; i++) {
        if (arr1->arr[i] != arr2->arr[i])
            { return false; }
    }

    return true;
}

int hashset_find
    (array_hashset_t *hashset, int_dynamic_array_t *arr)
{
    unsigned long hash = get_array_hashcode(arr);
    int bucket_ind = hash % hashset->size;
    bucket_t *buck = hashset->container[bucket_ind];

    for (int i = 0; i < buck.count; i++) {
        pair_t *element = buck.pairs[i];
        if (dyn_arr_are_equivalent(arr, element.arr))
            { return i; }
    }

    return -1; // not in bucket
}

enum hashset_returns hashset_resize(array_hashset_t *hashset) {
    array_hashset_t *new_hashset = create_hashset(hashset->size * 2);

    for (int i = 0; i < hashset->size; i++) {
        for (int j = 0; j < hashset->container[i]->count; j++) {
            if (hashset_add(
                new_hashset,
                hashset->container[i]->pairs[j]->arr
                ) == MEM_NOT_ALLOC)
                    { return MEM_NOT_ALLOC; };
        }
    }

    hashset_free(hashset);

    return SUCCESS;
}

enum hashset_returns hashset_add
    (array_hashset_t *hashset, int_dynamic_array_t *new_array)
{
    if (hashset == NULL)
        { return NULL_PTR; }

    int index_of_bucket = get_array_hashcode(new_array) % hashset->size;
    int last_in_bucket = -1 + hashset->container[index_of_bucket].count;

    int ind_found_el = hashset_find(hashset, new_array);
    pair_t element =
        hashset->container[index_of_bucket].pairs[ind_found_el];
    if (ind_found_el == -1) {
        element->arr = new_array;
    } else {
        element->arr[last_in_bucket] = new_array;
    }

    element.count++;

    if (hashset->container->pairs[ind_found_el] == STANDARD_BUCKET_SIZE) {
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
