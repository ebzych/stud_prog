#include "strsep.h"
#include "initiator_string.h"
#include "support_functions.h"
#include "strsub.h"


strings_array_t *strsep_sp(const string_t *string, char delim) {
    return strsep_ccp(string->str, delim);
}

strings_array_t *strsep_ccp(const char *cstring, char delim) {
    size_t count = count_char_inputs(cstring, delim);
    strings_array_t *substrings = malloc(sizeof(strings_array_t));
    substrings->size = count;
    substrings->container = malloc(count * sizeof(string_t));
    size_t saved_pos = 0, counter = 0;
    for (int i = 0; cstring[i] != '\0'; ++i) {
        if (cstring[i] == delim) {
            substrings->container[counter] =
                *str_sub(cstring, saved_pos, i);
            ++counter;
        }
        saved_pos = i + 1;
    }
    return substrings;
}
