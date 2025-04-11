#include <iostream>
using namespace std;

class Person {
public:
    int a;
    int b = 0;
};

struct Student : Person {
    int c = 69;
};


int main() {
    Student s;
    cout << s.c << endl;
    int *c = &s.c;
    Student *sp = &s;
    void *sh = (void *)((unsigned long)c - (unsigned long)sp);
    Person &p = s;
    cout << *((int *)(&p + (unsigned long)sh)) << endl;
    return 0;
}