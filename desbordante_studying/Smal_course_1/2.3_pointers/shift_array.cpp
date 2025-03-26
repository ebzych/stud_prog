#include <iostream>
using namespace std;

void rotate(int a[], unsigned size, int shift)
{
    int front_num = a[0];
    int saved_num = a[0];
    int local_shift;
    int i = 0, j = 0;
    do {
        local_shift = i - shift > 0 ?
            (i - shift) % size
            : size + (i - shift) % size;
        
        front_num = a[local_shift];
        a[local_shift] = saved_num;
        saved_num = front_num;
        
        if (local_shift <= i) {
            j++;
            i = j;
        }
        
        i++;
    } while (j < shift);
}

int main() {
    int a[5] = { 1, 2, 3, 4, 5 };
    rotate(a, 5, 2);
    for (int el : a) {
        cout << el << ' ';
    }

    cout << endl;

    return 0;
}