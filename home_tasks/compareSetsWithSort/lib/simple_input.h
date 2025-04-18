#ifndef SIMPLEINPUT
#define SIMPLEINPUT

#include <arrays.h>

int_duple_dynamic_array_t simply_get_from(void (*input_init_func)(int *));
int_duple_dynamic_array_t simply_get_from_console();
int_duple_dynamic_array_t create_DDarray_from_array(int (*array)[]);
// DON'T USES WITHOUT 'create_duple_dynamic_from_array()'
void _inner_foo(int *var);
void console_input(int *var);

#endif //SIMPLEINPUT