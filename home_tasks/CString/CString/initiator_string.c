#include "initiator_string.h"
#include "string_t.h"
#include <memory.h>

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
    str_cpy(to, from);
}

void init_string_spccp(string_t *to, const char *from) {
    to->allocated = 0;
    str_cpy(to, (char *)from);
}

void init_string_spsp(string_t *to, string_t *from) {
    to->allocated = 0;
    str_cpy(to, from);
}

void init_string_sps(string_t *to, string_t from) {
    to->allocated = 0;
    str_cpy(to, &from);
}

/*---------------------------------------------------------*/

void strcpy_cp(string_t *string, char *cstring) {
    int length = str_len(cstring);
    if (length == -1) {                             // if 'second' is NULL
        string->str = NULL;
        string->length = -1;
    } else {
        if (string->allocated == 0) {
            string->str = malloc(length + 1);
            string->allocated = length + 1;
        }
        else if (length >= string->allocated) {
            string->str = realloc(string->str, length + 1);
            string->allocated = length + 1;
        }
        memcpy(string->str, cstring, length + 1);
        string->length = length;
        string->str[length] = '\0';
    }
}

void strcpy_ccp(string_t *string, const char *cstring) {
    strcpy_cp(string, (char *)cstring);
}

void strcpy_sp(string_t *first, string_t *second) {
    strcpy_cp(first, second->str);
}
