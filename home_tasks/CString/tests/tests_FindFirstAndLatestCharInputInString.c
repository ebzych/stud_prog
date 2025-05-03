// tests_FindFirstAndLatestCharInputInString
#include "../../../unity_tests/Unity/extras/fixture/src/unity_fixture.h"
#include <strlrchr.h>

TEST_GROUP(FindFirstAndLatestCharInputInString);

TEST_SETUP(FindFirstAndLatestCharInputInString)
{
}

TEST_TEAR_DOWN(FindFirstAndLatestCharInputInString)
{
}

TEST(FindFirstAndLatestCharInputInString, FirstInput) {
    const char *cstring = "Vladimir Pugovkin";
    char *first_input = str_chr(cstring, ' ');
    TEST_ASSERT_EQUAL_PTR(cstring + 8, first_input);
}

TEST(FindFirstAndLatestCharInputInString, LatestInput) {
    const char *cstring = "Vladimir Putin";
    char *last_input = str_rchr(cstring, 'i');
    TEST_ASSERT_EQUAL_PTR(cstring + 12, last_input);
}

TEST(FindFirstAndLatestCharInputInString, CharNotInStringRetrunNull) {
    const char *cstring = "Vladimir Zhirik";
    char *input = str_rchr(cstring, '~');
    TEST_ASSERT_NULL(input);
}
