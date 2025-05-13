#ifndef CSTRING
#define CSTRING

#define USING_VALGRIND    // valgrind is using

 
#ifdef USING_VALGRIND
/*
    Code insertions for valgrind which mute valgrind 
    'Conditional jump or move depends on uninitialised 
    value(s)' for exact memory blocks
*/
#define VALGRIND_IS_USED(code) #code
#endif
#ifndef USING_VALGRIND
/*
    Code insertions for valgrind which mute valgrind 
    'Conditional jump or move depends on uninitialised 
    value(s)' for exact memory blocks
*/
#define VALGRIND_IS_USED(code)
#endif

#include <valgrind/memcheck.h>

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