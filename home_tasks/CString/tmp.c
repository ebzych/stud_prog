#include <stdio.h>

void hello(char *str) {
    str[0] = '!';
    printf("%s", str);
}

int main() {
    char const *str = " world!";
    hello((char *)str);
    return 0;
}