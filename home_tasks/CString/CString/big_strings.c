#include "big_strings.h"
#include <stdlib.h>
#include <time.h>

char *create_big_string(size_t number_of_letters) {
    char *big_string;
    if ( (big_string = malloc(number_of_letters)) == NULL) {
        return NULL;
    }
    for (int str_ptr = 0; str_ptr + sizeof(int) < number_of_letters; str_ptr += sizeof(int)) {
        srand(time(0));
        big_string[str_ptr] = rand();
    }
    
    return big_string;
}