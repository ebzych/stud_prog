#include <simple_input.h>
#include <arrays.h>
#include <stdio.h>
#include <stdlib.h>

int_duple_dynamic_array_t simply_get_from(void (*input_init_func)(long long *)) {
    int_duple_dynamic_array_t array;
    array.size = 0;

    printf("Enter number of subsets: ");
    input_init_func((long long *)&array.size);

    printf("%i\n", array.size);

    allocate_array(&array);

    for (int i = 0; i < array.size; i++) {
        array.container[i].size=0;
        printf("Enter number of elements at %i subset: ", i + 1);
        input_init_func((long long *)&array.container[i].size);

        printf("%i\n", array.container[i].size);

        allocate_subarray(&array.container[i]);

        printf("Enter elements of %i subset consistenly: ", i + 1);
        for (int j = 0; j < array.container[i].size; j++) {
            input_init_func((long long *)&get_subarray(&array, i)->container[j]);

            printf("%i\n", get_subarray(&array, i)->container[j]);
        }
    }

    return array;
}

void console_input(long long *var) {
    scanf("%i", var);
}

int_duple_dynamic_array_t simply_get_from_console() {
    simply_get_from(console_input);
}

// input array starts at number of subarrays; every subarray part begins at size of it
int_duple_dynamic_array_t create_duple_dynamic_from_array(int array[]) {
    int index = 0;

    // DON'T USES WITHOUT 'create_duple_dynamic_from_array()'
    void _inner_foo(long long *var) {
        *var = array[index];
        index++;
    }

    return simply_get_from(_inner_foo);
}
