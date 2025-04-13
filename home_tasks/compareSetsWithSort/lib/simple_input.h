#ifndef SIMPLEINPUT
#define SIMPLEINPUT

#include <arrays.h>

int_duple_dynamic_array_t simply_get_from(void (*input_init_func)(long long *));
int_duple_dynamic_array_t simply_get_from_console();
int_duple_dynamic_array_t create_duple_dynamic_from_array(int array[]);
// void _inner_foo(long long *var); ????????????????????
void console_input(long long *var);

#endif //SIMPLEINPUT