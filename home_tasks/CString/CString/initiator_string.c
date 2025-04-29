#include "initiator_string.h"
#include "string_t.h"

int strlen_cp(char *cstring) {
    if (cstring == NULL) {
        return -1;
    }
    int count = 0;
    while (cstring[count] != '\0') {
        ++count;
    }
    return count;
}

int strlen_ccp(const char *cstring) {
    strlen_cp((char *)cstring);
}

int strlen_sp(string_t *string) {
    strlen_cp(string->str);
}

/*---------------------------------------------------------*/

void init_string_spcp(string_t *to, char *from) {
    to->allocated = 0;
    memcpy(to, from);
}

void init_string_spccp(string_t *to, const char *from) {
    to->allocated = 0;
    memcpy(to, (char *)from);
}

void init_string_spsp(string_t *to, string_t *from) {
    to->allocated = 0;
    memcpy(to, from);
}

void init_string_sps(string_t *to, string_t from) {
    to->allocated = 0;
    memcpy(to, &from);
}

/*---------------------------------------------------------*/

void memcpy_cp(string_t *string, char *cstring) {
    int length = strlen(cstring);
    if (length == -1) {                             // if 'second' is NULL
        string->str = NULL;
        string->length = -1;
    } else {
        if (string->allocated == 0) {
            string->str = malloc(length + 1);
        }
        else if (length >= string->allocated) {
            string->str = realloc(string->str, length + 1);
        }
        string->allocated = length + 1;
        string->length = length;
        for (int i = 0; i < length + 1; ++i) {
            string->str[i] = cstring[i];
        }
    }
}

void memcpy_ccp(string_t *string, const char *cstring) {
    memcpy_cp(string, (char *)cstring);
}

void memcpy_sp(string_t *first, string_t *second) {
    memcpy_cp(first, second->str);
}
