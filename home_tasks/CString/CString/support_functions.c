#include "support_functions.h"
#include "string_t.h"
#include "initiator_string.h"

size_t count_char_inputs(const char *cstring, char delim) {
    size_t count = 1;           /* initialize with 1 because number of substrings
                                    greater than number of delimiter inputs by 1 */
    VALGRIND_MAKE_MEM_NOACCESS(cstring, str_len(cstring));
    // cstring = memset(cstring, cstring, str_len(cstring));   // for valgrind
    const char *str_ptr = cstring;
    while (*str_ptr != '\0') {
        if (*str_ptr == delim) {
            ++count;
        }
        ++str_ptr;
    }
    return count;
}