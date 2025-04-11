#define K 04
#include <stdio.h>

int main() {
    int k = K;
    struct kk {
        unsigned k1 : 1;
        unsigned k2 : 2;
        unsigned k3 : 1;
        unsigned k4 : 1;
    } pk;

    pk.k4 = 4;
    unsigned f1 = pk.k1;
    unsigned f4 = pk.k4;
    return 0;
}