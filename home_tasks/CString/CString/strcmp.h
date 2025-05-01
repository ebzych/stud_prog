#ifndef STRCMP
#define STRCMP

#include "string_t.h"
#include <stdbool.h>

#define str_cmp(first, second) _Generic( (second), \
        const char * : strcmp_spcp,                \
        char *       : strcmp_spcp,                 \
        string_t *   : strcmp_spsp,                  \
        string_t     : strcmp_sps                     \
    )(first, second)
    
bool strcmp_spcp(string_t *first,   char * second);
bool strcmp_spsp(string_t *first,   string_t *second);
bool strcmp_sps(string_t *first,    string_t second);

#endif  //STRCMP