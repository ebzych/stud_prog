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
    const char *string = "Hello World!";
    TEST_ASSERT_EQUAL(12, strlen(string));
}

TEST(CountingStringLength, NullString) {
    const char *string = "\0";
    TEST_ASSERT_EQUAL(0, strlen(string));
}

TEST(CountingStringLength, NullPointer) {
    char *string = NULL;
    TEST_ASSERT_EQUAL(-1, strlen(string));
}
