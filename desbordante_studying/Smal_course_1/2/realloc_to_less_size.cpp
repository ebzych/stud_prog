#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    setbuf(stdout, NULL);
    int *ptr = (int *)malloc(3 * sizeof(int));
    cout << ptr[2] << endl;
    ptr = (int *)realloc(ptr, 1);
    // for (int i = 0; i < 10000000; i++) {
    //     cout << i << ' ' << ptr[i] << endl;
    // }

    cout << 15444 * 4 / 1024 << endl;
    
    return 0;
}