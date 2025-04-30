#include "../../../unity_tests/Unity/extras/fixture/src/unity_fixture.h"
#include <initiator_string.h>
#include <strcmp.h> 
#include <strsub.h>

TEST_GROUP(SubstringSelection);

TEST_SETUP(SubstringSelection)
{
}

TEST_TEAR_DOWN(SubstringSelection)
{
}

TEST(SubstringSelection, SelectPartOfString) {
    string_t string;
    str_init(&string, "Hello World!");
    string_t substr = *str_sub(&string, 0, 5);
    TEST_ASSERT_TRUE(str_cmp(&substr, "Hello"));
    str_free(substr);
}

TEST(SubstringSelection, SelectFullString) {
    string_t string;
    str_init(&string, "Popa");
    string_t substr = *str_sub(&string, 0, 4);
    TEST_ASSERT_TRUE(str_cmp(&substr, "Popa"));
    str_free(substr);
}

TEST(SubstringSelection, SelectMoreThanPossible) {
    string_t string;
    str_init(&string, "");
    string_t substr = *str_sub(&string, 0, 2);
    TEST_ASSERT_NULL(substr.str);
    str_free(substr);
}
