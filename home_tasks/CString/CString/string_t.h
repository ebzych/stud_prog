#ifndef CSTRING
#define CSTRING

#include <stdlib.h>

typedef struct string {
    size_t length;
    char *str;
} string_t;

#endif //CSTRING