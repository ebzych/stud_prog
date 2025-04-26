#include <initiator_string.h>
#include "test_initiator_string.h"

void test_InitStringSpc_ConstCharPtr_ReturnCorrect() {
    const char *cstring = "Hello World!\0";
    string_t string;
    init_string_spccp(&string, cstring);
}
