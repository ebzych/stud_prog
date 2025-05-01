#ifndef STRCAT
#define STRCAT

#include <string_t.h>

#define str_cat(to, from) _Generic( (from),\
        char *       : strcat_ccp,          \
        const char * : strcat_ccp,           \
        string_t *   : strcat_sp,             \
        string_t     : strcat_s                \
    )(to, from)

string_t strcat_ccp(string_t *to, const char *from);
string_t strcat_sp(string_t *to, string_t *from);
string_t strcat_s(string_t *to, string_t from);

#endif  //STRCAT