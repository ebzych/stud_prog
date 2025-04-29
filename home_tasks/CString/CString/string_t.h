#ifndef CSTRING
#define CSTRING

#include <stdlib.h>

typedef struct {
    int length;         // string size; contain -1 if 'str' contain NULL
    char *str;
    size_t allocated;
} string_t;

// const string_t NULL_STRING = { .str = "", .length = 0 };

#endif //CSTRING