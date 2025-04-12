#include <simple_input.h>

int_duple_dynamic_array_t simply_get_from_console() {
    int_duple_dynamic_array_t array;

    printf("Enter number of subsets: ");
    scanf("%i", &array.size);

    array.container = malloc(array.size * sizeof(int_dynamic_array_t));

    for (int i = 0; i < array.size; i++) {
        printf("Enter number of elements at %i subset: ", i + 1);
        scanf("%i", &array.container[i].size);

        get_subarray(&array, i)->container = malloc(array.size * sizeof(int));

        printf("Enter elements of %i subset consistenly: ", i + 1);
        for (int j = 0; j < array.container[i].size; j++) {
            scanf("%i", &get_subarray(&array, i)->container[j]);
        }
    }

    return array;
}
