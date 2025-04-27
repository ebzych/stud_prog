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
    if (cstring == NULL) {
        return -1;
    }
    int count = 0;
    while (cstring[count] != '\0') {
        ++count;
    }
    return count;
}

int strlen_sp(string_t *string) {
    if (string == NULL) {
        return -1;
    }
    return string->length;
}

/*---------------------------------------------------------*/

void init_string_spcp(string_t *to, char *from) {
    to->str = malloc(sizeof(char));                 // allocating few bytes because memcpy is used with allocated strings 
    memcpy(to, from);
}

void init_string_spccp(string_t *to, const char *from) {
    to->str = malloc(sizeof(char));                 // allocating few bytes because memcpy is used with allocated strings
    memcpy(to, from);
}

void init_string_spsp(string_t *to, string_t *from) {
    to->str = malloc(sizeof(char));                 // allocating few bytes because memcpy is used with allocated strings
    memcpy(to, from);
}

void init_string_sps(string_t *to, string_t from) {
    to->str = malloc(sizeof(char));                 // allocating few bytes because memcpy is used with allocated strings
    memcpy(to, &from);
}

/*---------------------------------------------------------*/


/*
    Is used for freeing 'string' and copy the 'cstring' content into it

    Note: 'string' have to be allocated
*/
void memcpy_ccp(string_t *string, const char *cstring) {
    int length = strlen(cstring);
    free(string->str);
    string->str = NULL;
    if (length != -1) {                             // if 'second' is NULL
        string->str = malloc(length + 1);
    }
    string->length = length;
    for (int i = 0; i < length + 1; ++i) {
        string->str[i] = cstring[i];
    }
}

/*
    Is used for freeing 'string' and copy the 'cstring' content into it

    Note: 'string' have to be allocated
*/
void memcpy_cp(string_t *string, char *cstring) {
    int length = strlen(cstring);
    free(string->str);
    string->str = NULL;
    if (length != -1) {                             // if 'second' is NULL
        string->str = malloc(length + 1);
    }
    string->length = length;
    for (int i = 0; i < length + 1; ++i) {
        string->str[i] = cstring[i];
    }
}

/*
    Is used for freeing 'first' and copy the 'second' content into it

    Note: 'first' have to be allocated
*/
void memcpy_sp(string_t *first, string_t *second) {
    int length = second->length;
    free(first->str);
    first->str = NULL;
    if (length != -1) {                             // if 'second' is NULL
        first->str = malloc(length + 1);
    }
    first->length = length;
    for (int i = 0; i < length + 1; ++i) {
        first->str[i] = second->str[i];
    }
}
