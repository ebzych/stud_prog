#include "../../../unity_tests/Unity/extras/fixture/src/unity_fixture.h"
#include <strcat.h>
#include <initiator_string.h>
#include <strcmp.h>

TEST_GROUP(ConcatenatingStrings);

TEST_SETUP(ConcatenatingStrings)
{
}

TEST_TEAR_DOWN(ConcatenatingStrings)
{
}

TEST(ConcatenatingStrings, SimpleInputReturnCorrectStringAndLength) {
    string_t to, from;
    strinit(&to, "Oh, God, save the ");
    strinit(&from, "C!");
    strcat(&to, &from);
    TEST_ASSERT_TRUE(strcmp(&to, &from));
}
