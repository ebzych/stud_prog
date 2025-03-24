#include<stdio.h>
#include<stdlib.h>

void bar() {
  int b;
  printf("%i", b);
}

void foo() {
  int a = 69;
  bar();
}

int main() {
	foo();
	bar();
	return 0;
}

