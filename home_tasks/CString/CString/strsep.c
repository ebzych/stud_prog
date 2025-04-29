#include "strsep.h"
#include "initiator_string.h"
#include "support_functions.h"  // count_char_inputs() must be here



substrings_array_t strsep_sp(const string_t *string, char ch) {
    
}

substrings_array_t strsep_ccp(const char *cstring, char ch) {
    string_t string;
    str_init(&string, cstring);
    return strsep_sp(&string, ch);
}
