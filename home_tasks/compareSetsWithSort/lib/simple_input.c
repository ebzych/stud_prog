#include <simple_input.h>
#include <arrays.h>
#include <stdio.h>

int_duple_dynamic_array_t simply_get_from_console() {
    int_duple_dynamic_array_t array;
    array.size=0;

    printf("Enter number of subsets: ");
    scanf("%i", &array.size);
    printf("%i", array.size);

    allocate_array(&array);
    size_t s=array.size;

    for (int i = 0; i < s; i++) {
        array.container[i].size=0;
        printf("Enter number of elements at %i subset: ", i + 1);
        scanf("%i", &array.container[i].size);

        allocate_subarray(&array.container[i]);

        printf("Enter elements of %i subset consistenly: ", i + 1);
        for (int j = 0; j < array.container[i].size; j++) {
            scanf("%i", &get_subarray(&array, i)->container[j]);
        }
    }

    return array;
}
