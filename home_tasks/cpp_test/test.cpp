#include <iostream>
#define max(x, y) (x > y ? x : y)
using namespace std;

int main() {
	int a = 4 + max(3, 5);
	cout << a << endl;
	return 0;
}

