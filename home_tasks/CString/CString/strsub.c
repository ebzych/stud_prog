#include "strsub.h"
#include "initiator_string.h"
#include <memory.h>

string_t *strsub_ccp(const char *cstring, size_t start, size_t end) {
    string_t *substr = malloc(sizeof(string_t));
    size_t length = str_len(cstring);
    if (start > end || end > length) {
        substr->str = NULL;
        substr->length = -1;
    } else {
        char *copied = malloc(end - start + 1);
        substr->length = end - start;
        copied = memcpy(copied, cstring + start, substr->length);
        copied[substr->length] = '\0';
        substr->str = copied;
        substr->allocated = substr->length;
    }
    return substr;
}

string_t *strsub_sp(const string_t *string, size_t start, size_t end) {
    return strsub_ccp(string->str, start, end);
}