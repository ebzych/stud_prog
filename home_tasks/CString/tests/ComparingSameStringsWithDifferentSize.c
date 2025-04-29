#include "../../../unity_tests/Unity/extras/fixture/src/unity_fixture.h"
#include <strcmp.h>
#include <initiator_string.h>

TEST_GROUP(ComparingStrings);

TEST_SETUP(ComparingStrings)
{
}

TEST_TEAR_DOWN(ComparingStrings)
{
}

TEST(ComparingStrings, InputSameStringsWithDifferentSize) {
    string_t first, second;
    init_string(&first, "Hello World!");
    init_string(&second, "Hello World");
    TEST_ASSERT_FALSE(strcmp(&first, &second));
}
