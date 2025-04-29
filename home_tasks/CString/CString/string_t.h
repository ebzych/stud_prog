#ifndef CSTRING
#define CSTRING

#include <stdlib.h>

typedef struct string {
    size_t length;
    char *str;
    size_t allocated;
} string_t;

// const string_t NULL_STRING = { .str = "", .length = 0 };

#endif //CSTRING