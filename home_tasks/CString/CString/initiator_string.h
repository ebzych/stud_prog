#ifndef INIT_STR
#define INIT_STR

#include "string_t.h"
#include <stdlib.h>

/*
    Is used for initialize 'string' the content of 'cstring'

    Note: 'string' have to be non-allocated
*/
#define str_init(to, from) _Generic( (from),    \
        const char * : init_string_spccp,        \
        char *       : init_string_spccp,         \
        string_t *   : init_string_spsp,           \
        string_t     : init_string_sps              \
    )(to, from)

#define str_len(string) _Generic( (string), \
        const char * : strlen_ccp,           \
        char *       : strlen_ccp,            \
        string_t *   : strlen_sp               \
    )(string)

/*
    Is used for freeing 'string' and copy the 'cstring' content into it
*/
#define str_cpy(string, cstring) _Generic( (cstring),\
        const char * : strcpy_ccp,                    \
        char *       : strcpy_ccp,                     \
        string_t *   : strcpy_sp                        \
    )(string, cstring)

#define str_free(string) _Generic( (string), \
        string_t *  : strfree_s,              \
        string_t    : strfree_s                \
    )(string)

#define free_str_arr(strings_array) _Generic( (strings_array), \
        strings_array_t *   : freestrarr_sap,                   \
        strings_array_t     : freestrarr_sa                     \
    )(strings_array)

void init_string_spccp(string_t *to, const char *from);
void init_string_spsp(string_t *to, string_t *from);
void init_string_sps(string_t *to, string_t from);
int strlen_ccp(const char *string);
int strlen_sp(string_t *string);
void strcpy_ccp(string_t *string, const char *cstring);
void strcpy_sp(string_t *string, string_t *cstring);
void strfree_sp(string_t *string);
void strfree_s(string_t string);
void freestrarr_sap(strings_array_t *array);
void freestrarr_sa(strings_array_t array);

#endif //INIT_STR
