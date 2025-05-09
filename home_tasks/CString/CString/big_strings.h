#ifndef BIGSTRINGS
#define BIGSTRINGS

typedef struct string_s string_t;
typedef struct strings_array_s strings_array_t;
#include "string.h"
#include "initiator_string.h"

char get_random_char();
char *create_big_string(size_t number_of_letters);

#endif  //BIGSTRINGS
