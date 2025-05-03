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
    int letter_number = str_len(cstring) + 1;
    str_init(&string, cstring);
    TEST_ASSERT_EQUAL_CHAR_ARRAY(cstring, string.str, letter_number);
    TEST_ASSERT_EQUAL_INT32(letter_number, string.length + 1);
    str_free(string);
}

TEST(InitializationOfString, InputCharPtr) {
    string_t string;
    char *cstring = "Hello World!";
    int letter_number = str_len(cstring) + 1;
    str_init(&string, cstring);
    TEST_ASSERT_EQUAL_CHAR_ARRAY(cstring, string.str, letter_number);
    TEST_ASSERT_EQUAL_INT32(letter_number, string.length + 1);
    str_free(string);
}

TEST(InitializationOfString, InputStringPtr) {
    string_t string;
    string_t *string_p = malloc(sizeof(string_t));
    str_init(string_p, "Santa Clause <3");
    str_init(&string, string_p);
    TEST_ASSERT_EQUAL_CHAR_ARRAY(string_p->str, string.str, string_p->length + 1);
    TEST_ASSERT_EQUAL_INT32(string_p->length, string.length);
    str_free(string);
    str_free(*string_p);
}

TEST(InitializationOfString, InputString) {
    string_t string;
    string_t sstring;
    str_init(&sstring, "The cake is lie");
    str_init(&string, sstring);
    TEST_ASSERT_EQUAL_CHAR_ARRAY(sstring.str, string.str, sstring.length + 1);
    TEST_ASSERT_EQUAL_INT32(sstring.length, string.length);
    str_free(string);
    str_free(sstring);
}

TEST(InitializationOfString, InputNullPointer) {
    string_t string;
    char *cstring = NULL;
    int letter_number = str_len(cstring) + 1;
    str_init(&string, cstring);
    TEST_ASSERT_NULL(string.str);
    TEST_ASSERT_EQUAL_INT32(letter_number, string.length + 1);
    str_free(string);
}
