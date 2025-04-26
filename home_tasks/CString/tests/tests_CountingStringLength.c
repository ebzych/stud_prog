#include "../../../unity_tests/Unity/extras/fixture/src/unity_fixture.h"
#include <initiator_string.h>

TEST_GROUP(CountingStringLength);

TEST_SETUP(CountingStringLength)
{
}

TEST_TEAR_DOWN(CountingStringLength)
{
}

TEST(CountingStringLength, SimpleString) {
    static const char *string = "Hello World!\0";
    TEST_ASSERT_EQUAL(12, strlen(string));
}

TEST(CountingStringLength, NullString) {
    static const char *string = "\0";
    TEST_ASSERT_EQUAL(0, strlen(string));
}
