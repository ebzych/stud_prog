#include "../../../unity_tests/Unity/extras/fixture/src/unity_fixture.h"

TEST_GROUP_RUNNER(CountingStringLength) {
    RUN_TEST_CASE(CountingStringLength, SimpleString);
    RUN_TEST_CASE(CountingStringLength, NullString);
}
