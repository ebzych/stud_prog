#ifndef INIT_STR
#define INIT_STR

#include "string_t.h"
#include <stdlib.h>

/*
    Is used for initialize 'string' the content of 'cstring'

    Note: 'string' have to be non-allocated
*/
#define str_init(to, from) _Generic( (from), \
        const char * : init_string_spccp,        \
        char *       : init_string_spcp,          \
        string_t *   : init_string_spsp,           \
        string_t     : init_string_sps              \
    )(to, from)

#define str_len(string) _Generic( (string), \
        const char * : strlen_ccp,           \
        char *       : strlen_cp,             \
        string_t *   : strlen_sp               \
    )(string)

/*
    Is used for freeing 'string' and copy the 'cstring' content into it
*/
#define str_cpy(string, cstring) _Generic( (cstring), \
        const char * : strcpy_ccp,                    \
        char *       : strcpy_cp,                      \
        string_t *   : strcpy_sp                        \
    )(string, cstring)

void init_string_spcp(string_t *to, char *from);
void init_string_spccp(string_t *to, const char *from);
void init_string_spsp(string_t *to, string_t *from);
void init_string_sps(string_t *to, string_t from);
int strlen_cp(char *string);
int strlen_ccp(const char *string);
int strlen_sp(string_t *string);
void strcpy_ccp(string_t *string, const char *cstring);
void strcpy_cp(string_t *string, char *cstring);
void strcpy_sp(string_t *string, string_t *cstring);

#endif //INIT_STR
