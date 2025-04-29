#include <stdio.h>
#include <stdlib.h>

void hello(char *str) {
    // str[0] = '!';
    printf("%s\n", str);
}

int main() {
    char const *str = " world!";
    hello((char *)str);
    char *str2 = malloc(4);
    char const *str3 = (char const *)str2;
    printf("%i %i\n", str2, str3);
    return 0;
}