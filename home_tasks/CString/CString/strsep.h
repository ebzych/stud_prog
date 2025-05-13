#ifndef STRSEP
#define STRSEP

#include "string_t.h"

/*
    Return substrings of string separated by delimiter
    Without collision
*/
#define str_sep(string, delim) _Generic((string),     \
        string_t *      : strsep_sp,                   \
        const char *    : strsep_ccp,                   \
        char *          : strsep_ccp                     \
    )(string, delim)

strings_array_t *strsep_sp(const string_t *string, char delim);
strings_array_t *strsep_ccp(const char *cstring, char delim);

#endif  //STRSEP