#include <initiator_string.h>
#include "test_initiator_string.h"

void test_Strlen_ConstCharPtr_ReturnCorrect() {
    const char *string = "Hello World!\0";
    TEST_ASSERT_EQUAL(12, strlen(string));

    string = "\0";
    TEST_ASSERT_EQUAL(0, strlen(string));
}

void test_InitStringSpc_ConstCharPtr_ReturnCorrect() {
    const char *cstring = "Hello World!\0";
    string_t string;
    init_string_spccp(&string, cstring);
}
