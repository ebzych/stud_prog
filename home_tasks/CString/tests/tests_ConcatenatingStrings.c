#include "../../../unity_tests/Unity/extras/fixture/src/unity_fixture.h"
#include <strcat.h>
#include <initiator_string.h>
#include <strcmp.h>
#include <big_strings.h>

TEST_GROUP(ConcatenatingStrings);

TEST_SETUP(ConcatenatingStrings)
{
}

TEST_TEAR_DOWN(ConcatenatingStrings)
{
}

TEST(ConcatenatingStrings, SimpleInputReturnCorrectStringAndLength) {
    string_t to, from;
    str_init(&to, "Oh, God, save the ");
    str_init(&from, "C!");
    str_cat(&to, &from);
    printf("%s", to.str);
    TEST_ASSERT_TRUE(str_cmp(&to, "Oh, God, save the C!"));
    // str_free(to);
    // str_free(from);
}

//  Important: string have to get correct address in 'str_cat()'
TEST(ConcatenatingStrings, InputBigStringReturnCorrectStringAndLengthAndAddress) {
    string_t string_1, string_2;
    char *big_string_1 = create_big_string(10000);
    char *big_string_2 = create_big_string(10000);
    str_init(&string_1, big_string_1);
    str_init(&string_2, big_string_2);
    str_cat(&string_1, &string_2);
    TEST_ASSERT_EQUAL_INT32(20000, str_len(&string_1));
    // str_free(string_1);
    // str_free(string_2);
    free(big_string_1);
    free(big_string_2);
}
