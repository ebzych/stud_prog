#include <iostream>
using namespace std;

int foo(int (&a)[3]) {
    return sizeof(a);
}

int main() {
    setbuf(stdout, NULL);
    int a = 5, b = 2;
    int *p = (int *)123;
    int &la = a, &lb = b;
    cout << la + lb << ' ' << p << endl;

    int f[3] = {};
    cout << sizeof(f) << ' ' << foo(f) << endl;

    int l = 5;
    const int *i;
    int const *j;
    int *const k = &l;
    int const* const Int = &l;
    j = i;
    // k = j;

    return 0;
}