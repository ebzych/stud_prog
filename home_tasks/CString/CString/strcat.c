#include <strcat.h>
#include <initiator_string.h>
#include <stdlib.h>
#include <memory.h>

string_t strcat_cp(string_t *to, char *from) {
    int start = str_len(to);
    int length = str_len(from);
    if (to->str != NULL && from != NULL) {
        to->str = memcpy(to->str + start, from, length) - start;
        to->length = length += start;
        to->str[length] = '\0';
        to->allocated = to->allocated < length ? length : to->allocated;
    } else {
        to->str = NULL;
        to->length = -1;
    }
    return *to;
}

string_t strcat_ccp(string_t *to, const char *from) {
    return strcat_cp(to, (char *)from);
}

string_t strcat_sp(string_t *to, string_t *from) {
    return strcat_cp(to, from->str);
}

string_t strcat_s(string_t *to, string_t from) {
    return strcat_cp(to, from.str);
}
