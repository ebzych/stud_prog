/*
    Question: How does pointers arithmetic work?
    Answer: Very cool: *(arr + i) === arr[i].
*/

#include <iostream>
using namespace std;

int main() {
    int arr[2] = { 121, 122 };
    int *arr_p = &arr[0];
    cout << *(arr_p + 1) << " " << sizeof(int) << " " << sizeof(int *) << endl;

    char arr_ch[2] = { 'a', 'b' };
    char *arr_ch_p = &arr_ch[0];
    cout << *(arr_ch_p + 1) << " " << sizeof(char) << " " << sizeof(char *) << endl;

    return 0;
}