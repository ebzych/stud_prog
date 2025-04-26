#include "initiator_string.h"
#include "string_t.h"


size_t strlen_cp(char *string) {
    size_t count = 0;
    while (string[count] != '\0') {
        ++count;
    }
    return count;
}

size_t strlen_ccp(const char *string) {
    char *non_const_string = convert_constCharPtr_into_charPtr(string);
    return strlen_cp(non_const_string);
}

size_t strlen_sp(string_t *string) {
    return strlen_cp(string->str);
}

/*---------------------------------------------------------*/

void init_string_spcp(string_t *to, char *from) {
    to->str = from;
    to->length = strlen_spcp(from);
}

void init_string_spccp(string_t *to, const char *from) {
    char *cstring = convert_constCharPtr_into_charPtr(from);
    init_string_spcp(to, cstring);
}

void init_string_spsp(string_t *to, string_t *from) {
    init_string_spccp(to, from->str);
}

void init_string_sps(string_t *to, string_t from) {
    init_string_spccp(to, from.str);
}

/*---------------------------------------------------------*/

char *convert_constCharPtr_into_charPtr(const char *cstring) {
    size_t length = strlen(cstring);
    char *string = malloc(length + 1);
    for (int i = 0; i < length + 1; ++i) {
        string[i] = cstring[i];
    }
    return string;
}
