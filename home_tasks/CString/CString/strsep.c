#include "strsep.h"
#include "initiator_string.h"
#include "support_functions.h"



substrings_array_t strsep_sp(const string_t *string, const char *delim) {
    
}

substrings_array_t strsep_ccp(const char *cstring, const char *delim) {
    string_t string;
    str_init(&string, cstring);
    return strsep_sp(&string, ch);
}
