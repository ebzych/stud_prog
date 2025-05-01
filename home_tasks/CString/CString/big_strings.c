#include "big_strings.h"
#include <stdlib.h>
#include <time.h>

char get_random_char() {
    static const int ALPHABET_SIZE = 256;
    srand(clock());
    return 1 + (size_t)rand() % (ALPHABET_SIZE - 1);
}

//  Return C-string size 'number_of_letter' if memory can be allocated else NULL 
char *create_big_string(size_t number_of_letters) {
    char *big_string;
    if ( (big_string = malloc(1 + number_of_letters)) == NULL) {    // '+ 1' for null-terminator
        return NULL;
    }
    for (int length = 0; length < number_of_letters; ++length) {
        big_string[length] = get_random_char();
    }
    return big_string;
}