#include <iostream>
#define DEBUG
using namespace std;

void debug_print(int a[], size_t size) {
    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void left_shift(int a[], unsigned size, int shift, int pos) {
#ifdef DEBUG
    debug_print(a, size);
#endif //DEBUG

    int save_val = a[pos];
    a[pos] = a[(pos + shift) % size];
    if (pos < size) {
        left_shift(a, size, shift, pos + 1);

#ifdef DEBUG
        debug_print(a, size);
#endif //DEBUG

        int replacement_pos = (size + pos - shift) % size;
        a[replacement_pos] = save_val;
    }
}

void rotate(int a[], unsigned size, int shift) {
    if (size == 0)
        { return; }

    shift %= size;
    left_shift(a, size, shift, 0);
}

int main() {
#ifdef DEBUG
int a[0] = {};
        rotate(a, 0, 6);
        cout << 6 << " ";
        for (int i = 0; i < 5; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
#endif

#ifndef DEBUG
    for (int step = 0; step <= 10; step++) {
        int a[5] = { 1, 2, 3, 4, 5 };
        rotate(a, 5, step);
        cout << step << " ";
        for (int i = 0; i < 5; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
#endif //DEBUG

    return 0;
}