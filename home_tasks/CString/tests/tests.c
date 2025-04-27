#include "../../../unity_tests/Unity/extras/fixture/src/unity_fixture.h"

void run_all_tests() {
    RUN_TEST_GROUP(CountingStringLength);
    RUN_TEST_GROUP(InitializationOfString);
    RUN_TEST_GROUP(CreatingBigStrings);
}

int main(int argc, const char *argv) {
    setbuf(stdout, NULL);
    return UnityMain(argc, &argv, run_all_tests);
}