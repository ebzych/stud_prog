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
    str_init(&first, "Hello World!");
    str_init(&second, "Hello World");
    TEST_ASSERT_FALSE(str_cmp(&first, &second));
    str_free(first);
    str_free(second);
}
