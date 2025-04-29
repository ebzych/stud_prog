#include "../../../unity_tests/Unity/extras/fixture/src/unity_fixture.h"
#include <big_strings.h>

TEST_GROUP(CreatingBigStrings);

TEST_SETUP(CreatingBigStrings)
{
}

TEST_TEAR_DOWN(CreatingBigStrings)
{
}

TEST(CreatingBigStrings, Creating10000Symbols_NotSegFaultOrOverheadMemoryUsing) {
    size_t string_size = 10000;
    string_t string;
    char *big_string = create_big_string(string_size);
    strinit(&string, big_string);
    TEST_ASSERT_EQUAL_INT32(string_size, string.length);
}
