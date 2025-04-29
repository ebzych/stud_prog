#include "strsub.h"
#include "initiator_string.h"
#include <memory.h>

string_t str_sub(const string_t *string, size_t start, size_t end) {
    string_t substr;
    if (start > end || end > string->length) {
        substr.str = NULL;
        substr.length = -1;
    } else {
        char *copied;
        substr.length = end - start;
        copied = memcpy(copied, string->str + start, substr.length);
        copied[substr.length] = '\0';
        substr.str = copied;
        substr.allocated = substr.length;
    }
    return substr;
}