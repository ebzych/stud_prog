#include "initiator_string.h"
#include <memory.h>

int strlen_ccp(const char *cstring) {
    VALGRIND_MAKE_MEM_DEFINED(cstring, 1);
    if (cstring == NULL) {
        return -1;
    }
    int count = 0;
    VALGRIND_MAKE_MEM_UNDEFINED(cstring[count], 1);
    while (cstring[count] != '\0') {
        ++count;
        VALGRIND_MAKE_MEM_DEFINED(cstring[count], 1);
    }
    return count;
}

int strlen_sp(string_t *string) {
    strlen_ccp(string->str);
}

/*---------------------------------------------------------*/

void init_string_spccp(string_t *to, const char *from) {
    to->allocated = 0;
    str_cpy(to, from);
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

void strcpy_ccp(string_t *string, const char *cstring) {
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
        string->str = memcpy(string->str, cstring, length + 1);
        string->length = length;
        string->str[length] = '\0';
    }
}

void strcpy_sp(string_t *first, string_t *second) {
    strcpy_ccp(first, second->str);
}

/*---------------------------------------------------------*/

void strfree_s(string_t string) {
    free(string.str);
}

void strfree_sp(string_t *string) {
    free(string->str);
    free(string);
}

/*---------------------------------------------------------*/

void freestrarr_sap(strings_array_t *array) {
    free(array->container);
    free(array);
}

void freestrarr_sa(strings_array_t array) {
    free(array.container);
}
