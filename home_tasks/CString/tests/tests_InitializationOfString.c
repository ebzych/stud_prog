/*
*-------------------------------------------------------------------------------*
    Testing initializing string and memory copying in composite initialization 
*-------------------------------------------------------------------------------*
*/  
#include "../../../unity_tests/Unity/extras/fixture/src/unity_fixture.h"
#include <initiator_string.h>


TEST_GROUP(InitializationOfString);

TEST_SETUP(InitializationOfString)
{
}

TEST_TEAR_DOWN(InitializationOfString)
{
}

TEST(InitializationOfString, InputConstCharPtr) {
    string_t string;
    const char *cstring = "P=NP";
    int letter_number = strlen(cstring) + 1;
    init_string(&string, cstring);
    TEST_ASSERT_EQUAL_CHAR_ARRAY(cstring, string.str, letter_number);
    TEST_ASSERT_EQUAL_INT32(letter_number, string.length + 1);
}

TEST(InitializationOfString, InputCharPtr) {
    string_t string;
    char *cstring = "Hello World!";
    int letter_number = strlen(cstring) + 1;
    init_string(&string, cstring);
    TEST_ASSERT_EQUAL_CHAR_ARRAY(cstring, string.str, letter_number);
    TEST_ASSERT_EQUAL_INT32(letter_number, string.length + 1);
}

TEST(InitializationOfString, InputStringPtr) {
    string_t string;
    string_t *string_p = malloc(sizeof(string_t));
    string_p->length = 4;
    string_p->str = "Santa Clause <3";
    init_string(&string, string_p);
    TEST_ASSERT_EQUAL_CHAR_ARRAY(string_p->str, string.str, string_p->length + 1);
    TEST_ASSERT_EQUAL_INT32(string_p->length, string.length);
    free(string_p);
}

TEST(InitializationOfString, InputString) {
    string_t string;
    string_t string_p = { .length = 4, .str = "The cake is lie!" };
    init_string(&string, string_p);
    TEST_ASSERT_EQUAL_CHAR_ARRAY(string_p.str, string.str, string_p.length + 1);
    TEST_ASSERT_EQUAL_INT32(string_p.length, string.length);
}

TEST(InitializationOfString, InputNullPointer) {
    string_t string;
    char *cstring = NULL;
    int letter_number = strlen(cstring) + 1;
    init_string(&string, cstring);
    TEST_ASSERT_NULL(string.str);
    TEST_ASSERT_EQUAL_INT32(letter_number, string.length + 1);
}
