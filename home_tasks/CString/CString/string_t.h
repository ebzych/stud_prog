#ifndef CSTRING
#define CSTRING

#include <stdlib.h>
#include "initiator_string.h"
#include "big_strings.h"
#include "strcat.h"
#include "strcmp.h"
#include "strlrchr.h"
#include "strsep.h"
#include "strsub.h"
#include "support_functions.h"

typedef struct string_s {
    int length;         // string size; contain -1 if 'str' contain NULL
    char *str;
    size_t allocated;   // info about allocated bytes for 'str' which we know exactly
} string_t;

typedef struct strings_array_s {
    size_t size;
    string_t *container;
} strings_array_t;

// const string_t NULL_STRING = { .str = "", .length = 0 };

#endif //CSTRING