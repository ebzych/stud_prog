// include<stdbool.h>
// #include<stdbool.h>
#include<stdio.h>

void main() {
#if __bool_true_false_are_defined == 1
	printf("hello");
#endif
}
