#include <init_array.h>
#include <compsets.h>
#include <parsing_from_console.h>
#include <arrays.h>

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
    int_duple_dynamic_array_t *arr;
    arr->size = 2;
    arr->container =
        malloc(arr->size * sizeof(int_duple_dynamic_array_t *));
    arr->container[0].size = 2;
    arr->container[0].container =
        malloc(arr->container[0].size * sizeof(int_dynamic_array_t *));
    arr->container[1].container =
        malloc(sizeof(int_dynamic_array_t *));
    arr->container[0].container[0] = 2;
    arr->container[0].container[1] = 1;
    arr->container[1].container[0] = 1;

    qsort(arr->container, arr->container[0].size, arr->container[0].size * sizeof(int_dynamic_array_t), ptr);

    for (int i = 0; i < arr->size; i++) {
        for (int j = 0; j < arr->container[i].size; j++) {
            printf("%i ", arr->container[i].container[j]);
        }
        printf("\n");
    }

    return 0;
}