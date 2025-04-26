#include "../../../unity_tests/Unity/extras/fixture/src/unity_fixture.h"

TEST_GROUP_RUNNER(CountingStringLength) {
    RUN_TEST_CASE(CountingStringLength, SimpleString);
    RUN_TEST_CASE(CountingStringLength, NullString);
}

TEST_GROUP_RUNNER(InitializationOfString) {
    RUN_TEST_CASE(InitializationOfString, InputConstCharPtr);
    RUN_TEST_CASE(InitializationOfString, InputCharPtr);
    RUN_TEST_CASE(InitializationOfString, InputStringPtr);
    RUN_TEST_CASE(InitializationOfString, InputString);
}

TEST_GROUP_RUNNER(CreatingBigStrings) {
    RUN_TEST_CASE(CreatingBigStrings,
        Creating10000Symbols_NotSegFaultOrOverheadConstantMemoryUsing);
}
