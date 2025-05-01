#ifndef CSTRING
#define CSTRING

#include <stdlib.h>

typedef struct {
    int length;         // string size; contain -1 if 'str' contain NULL
    char *str;
    size_t allocated;   // info about allocated bytes for 'str' which we know exactly
} string_t;

typedef struct {
    size_t size;
    string_t *container;
} strings_array_t;

// const string_t NULL_STRING = { .str = "", .length = 0 };

#endif //CSTRING