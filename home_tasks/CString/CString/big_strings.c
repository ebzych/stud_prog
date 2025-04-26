#include "big_strings.h"
#include <stdlib.h>
#include <time.h>

const char *create_big_string(size_t number_of_letters) {
    char *big_string;
    if ( (big_string = malloc(number_of_letters)) == NULL) {
        return NULL;
    }
    for (int str_ptr = 0; str_ptr + sizeof(int) < number_of_letters; str_ptr += sizeof(int)) {
        srand(105000);
        big_string[str_ptr] = rand();
    }
    const char *const_big_string = big_string;
    free(big_string);
    return const_big_string;
}