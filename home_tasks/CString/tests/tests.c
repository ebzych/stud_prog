#include "../../../unity_tests/Unity/extras/fixture/src/unity_fixture.h"

void run_all_tests() {
    return;
}

int main(int argc, const char *argv) {
    return UnityMain(argc, &argv, run_all_tests);
}