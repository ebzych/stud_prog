#include <stdio.h>

void b();

void foo() {
    extern int i;
    printf("foo");
    printf("%i", i);
}

void a(char const* s) {
    printf("%s", s);
    b();
}

int main() {
    a("hello\0");
    return 0;
}
