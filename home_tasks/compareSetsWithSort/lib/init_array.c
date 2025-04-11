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
            get_subarray(array, index)->container[init_number] =
                 get_number_from_str(&str[i]);
            init_number++;
        }
    }

    if (str[i] == '\0')
        { return -1; }

    return 0;
}

int initialize_subarrays(char *str, int_duple_dynamic_array_t *array) {
    int str_len = strlen(str);
    int openning_counter = 0; // must be on 0 or 1 position
    // iterations are made after first '<' and before last '>'
    for (int i = 1;
         (i + 1 < str_len) && (openning_counter == 0 || openning_counter == 1); // if -1, hence excess '>', if 2, hence excess '<'
         i++)
    {
        if (handle_char(&str[i], array, i, &openning_counter) == -1)
            { return -1; }
    }

    if (openning_counter != 0)  // hence incorrect combination of opened and closed branches
        { return -1; }
    else
        { return 0; }
}
