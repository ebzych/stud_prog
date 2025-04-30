#include "../../../unity_tests/Unity/extras/fixture/src/unity_fixture.h"

TEST_GROUP_RUNNER(CountingStringLength) {
    RUN_TEST_CASE(CountingStringLength, SimpleString);
    RUN_TEST_CASE(CountingStringLength, NullString);
    RUN_TEST_CASE(CountingStringLength, NullPointer);
}

TEST_GROUP_RUNNER(InitializationOfString) {
    RUN_TEST_CASE(InitializationOfString, InputConstCharPtr);
    RUN_TEST_CASE(InitializationOfString, InputCharPtr);
    RUN_TEST_CASE(InitializationOfString, InputStringPtr);
    RUN_TEST_CASE(InitializationOfString, InputString);
    RUN_TEST_CASE(InitializationOfString, InputNullPointer);
}

TEST_GROUP_RUNNER(CreatingBigStrings) {
    RUN_TEST_CASE(CreatingBigStrings,
        Creating10000Symbols_NotSegFaultOrOverheadMemoryUsing);
}

TEST_GROUP_RUNNER(ComparingStrings) {
    RUN_TEST_CASE(ComparingStrings, InputSameStringsWithDifferentSize);
}

TEST_GROUP_RUNNER(ConcatenatingStrings) {
    RUN_TEST_CASE(ConcatenatingStrings, SimpleInputReturnCorrectStringAndLength);
    RUN_TEST_CASE(ConcatenatingStrings, InputBigStringReturnCorrectStringAndLengthAndAddress);
}

TEST_GROUP_RUNNER(SubstringSelection) {
    RUN_TEST_CASE(SubstringSelection, SelectPartOfString);
    RUN_TEST_CASE(SubstringSelection, SelectFullString);
    RUN_TEST_CASE(SubstringSelection, SelectMoreThanPossible);
}

TEST_GROUP_RUNNER(SeparatingString) {
    RUN_TEST_CASE(SeparatingString, InputStringWithNeededSymbolReturnCorrectArrayWithSubstrings);
    RUN_TEST_CASE(SeparatingString, CharIsNotInStringReturnNull);
}
