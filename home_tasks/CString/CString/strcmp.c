#include "strcmp.h"


bool strcmp_spcp(string_t *first,   char * second) {
    char *safety_first_ptr = first->str;
    for (int i = 0; *safety_first_ptr != '\0' && *second != '\0'; ++safety_first_ptr, ++second) {
        if (*safety_first_ptr != *second) {
            return false;
        }
    }
    if (*safety_first_ptr != *second) {
        return false;
    }
    return true;
}

bool strcmp_spsp(string_t *first,   string_t *second) {
    return strcmp_spcp(first, second->str);
}

bool strcmp_sps(string_t *first,    string_t second) {
    return strcmp_spcp(first, second.str);
}
