#include <init_array.h>
#include <compsets.h>
#include <parsing_from_console.h>
#include <arrays.h>
#include <simple_input.h>

/*
module1: input


module2: comparing
    if (size1 != size2) {
        goto bad;
    }

    for (int i = 0; i < size1; i++) {
        qsort(arr1[i], comparator1());
    }

    for (int i = 0; i < size2; i++) {
        qsort(arr2[i], comparator1());
    }

    qsort(arr1, comparator2());
    qsort(arr2, comparator2());

    for (int i = 0; i < size12; i++) {
        if (arr1[i].size != arr2[i].size) {
            goto bad;
        }

        for (int j = 0; j < arr1[i].size; j++) {
            if (arr1[i][j] != arr2[i][j]) {
                goto bad;
            }
        }
    }

    "ARE SAME"

    bad:
        "DIFFERENT."
    */

int main() {
    int_duple_dynamic_array_t arr1 = simply_get_from_console();
    int_duple_dynamic_array_t arr2 = simply_get_from_console();
    printf("%i", multisets_are_equal(&arr1, &arr2));

    // arr->size = 2;
    // arr->container =
    //     malloc(arr->size * sizeof(int_duple_dynamic_array_t *));
    // arr->container[0].size = 2;
    // arr->container[0].container =
    //     malloc(arr->container[0].size * sizeof(int_dynamic_array_t *));
    // arr->container[1].container =
    //     malloc(sizeof(int_dynamic_array_t *));
    // arr->container[0].container[0] = 2;
    // arr->container[0].container[1] = 1;
    // arr->container[1].container[0] = 1;
    // arr->container[1].size = 1;

    // int_duple_dynamic_array_t *arr0;
    // arr0 = malloc(sizeof(int_duple_dynamic_array_t));
    // arr0->size = 2;
    // arr0->container =
    //     malloc(arr0->size * sizeof(int_duple_dynamic_array_t *));
    // arr0->container[1].size = 2;
    // arr0->container[1].container =
    //     malloc(arr0->container[0].size * sizeof(int_dynamic_array_t *));
    // arr0->container[0].container =
    //     malloc(sizeof(int_dynamic_array_t *));
    // arr0->container[1].container[1] = 2;
    // arr0->container[1].container[0] = 1;
    // arr0->container[0].container[0] = 1;
    // arr0->container[0].size = 1;

    // printf("%i", multisets_are_equal(arr, arr0));

    return 0;
}