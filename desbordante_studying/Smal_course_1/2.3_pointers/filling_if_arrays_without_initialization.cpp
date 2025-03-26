/*
    Question: Filling zeros if array hasn't initializing?
    Answer: NO
*/

#include <iostream>
using namespace std;

int main() {
    int arr1[10] = { 1 };
    for (int i = 0; i < 10; i++) {
        cout << arr1[i] << endl;
    }

    int arr2[10];
    for (int i = 0; i < 10; i++) {
        cout << arr2[i] << endl;
    }

    return 0;
}
