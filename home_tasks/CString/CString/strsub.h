#ifndef STRSUB
#define STRSUB

#include <stdlib.h>
#include "string_t.h"

#define str_sub(string, start, end) _Generic( (string), \
        const char * : strsub_ccp,                       \
        char *       : strsub_ccp,                        \
        string_t *   : strsub_sp                           \
    )(string, start, end)

string_t *strsub_ccp(const char *cstring, size_t start, size_t end);
string_t *strsub_sp(const string_t *string, size_t start, size_t end);

#endif  //STRSUB