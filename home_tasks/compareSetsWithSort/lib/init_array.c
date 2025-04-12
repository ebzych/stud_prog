#include <init_array.h>

// Resize rows of double dynamic array in 2 times
int realloc_container(int_duple_dynamic_array_t *array) {
    if ((array->container =
             realloc(array->container, array->size * 2)) == NULL)
    {
        return -1;
    }

    return 0;
}

int alloc_subarray(char *str, int_duple_dynamic_array_t *array, int index_subarray) {
    if (index_subarray > array->size) {
        if (realloc_container(array) == -1)
            { return -1; }
    }

    int number_items = count_items(str);
    if (number_items == -1)
        { return -1; }

    get_subarray(array, index_subarray)->container =  //////////
        malloc(number_items * sizeof(int));

    get_subarray(array, index_subarray)->size = number_items;

    array->size++;

    return 0;
}

int init_subarray(char *str, int_duple_dynamic_array_t *array, int index) {
    alloc_subarray(str, array, index);
    int init_number = 0;
    int i = 0;
    for ( ; (str[i] != '\0') && (str[i - 1] != '>'); i++) {
        if (str[i] == ',') {
            if ( (get_subarray(array, index)->container[init_number] =
                 get_number_from_str(&str[i])) != SMALLEST_LLONG)
                init_number++;
            else
                { return -1; }
        }
    }

    if (str[i] == '\0')
        { return -1; }

    return 0;
}
