#include <strcat.h>
#include <initiator_string.h>
#include <stdlib.h>

string_t strcat_cp(string_t *to, char *from) {
    int length = strlen(to) + strlen(from);
    if (length <= -1) {                             // if 'first' or 'second' is NULL
        to->str = NULL;
        to->length = -1;
        return *to;
    } else {
        if (to->allocated == 0) {
            to->str = malloc(length + 1);
        }
        else if (length >= to->allocated) {
            to->str = realloc(to->str, length + 1);
        }
        to->allocated = length + 1;
        to->length = length;
        for (int i = 0; i < length + 1; ++i) {
            to->str[i] = from[i];
        }
    }
}
string_t strcat_ccp(string_t *to, const char *from);
string_t strcat_sp(string_t *to, string_t *from) { }
string_t strcat_s(string_t *to, string_t from);