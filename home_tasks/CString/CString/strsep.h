#ifndef STRSEP
#define STRSEP

#include "string_t.h"

#define str_sep(string, ch) _Generic( (string), \
        string_t *      : strsep_sp,             \
        const char *    : strsep_ccp,             \
        char *          : strsep_ccp               \
    )(string, ch)

substrings_array_t strsep_sp(const string_t *string, char ch);
substrings_array_t strsep_ccp(const char *cstring, char ch);

#endif  //STRSEP