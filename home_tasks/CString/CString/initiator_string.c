#include "initiator_string.h"
#include "string_t.h"

#define INIT_STRING(a, b) _Generic( (b), \
        const char * : init_string_spccp, \
        char *       : init_string_spccp,  \
        string_t *   : init_string_spsp,    \
        string_t     : init_string_sps       \
    )(a, b)

void init_string_spccp(string_t *to, const char *from) {
    to->str = from;
    to->length = strlen(from);
}

void init_string_spsp(string_t *to, string_t *from) {
    init_string_spccp(to, from->str);
}

void init_string_sps(string_t *to, string_t from) {
    init_string_spccp(to, from.str);
}

size_t strlen(const char *string) {
    size_t count = 0;
    while (string[count] != '\0') {
        ++count;
    }
    return count;
}
