#ifndef INIT_STR
#define INIT_STR

#include "string_t.h"
#include <stdlib.h>

#define init_string(to, from) _Generic( (from), \
        const char * : init_string_spccp,        \
        char *       : init_string_spccp,         \
        string_t *   : init_string_spsp,           \
        string_t     : init_string_sps              \
    )(to, from)

#define str_len(string) _Generic( (string), \
        const char * : strlen_ccp,           \
        char *       : strlen_cp,             \
        string_t     : strlen_sp                \
    )(string)

char *convert_constCharPtr_into_charPtr(const char *cstring);
void init_string_spcp(string_t *to, char *from);
void init_string_spccp(string_t *to, const char *from);
void init_string_spsp(string_t *to, string_t *from);
void init_string_sps(string_t *to, string_t from);
size_t strlen_cp(char *string);
size_t strlen_ccp(const char *string);
size_t strlen_sp(string_t *string);

#endif //INIT_STR
