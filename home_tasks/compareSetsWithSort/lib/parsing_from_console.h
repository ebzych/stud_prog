#ifndef PARSING
#define PARSING

#include <arrays.h>
#include <init_array.h>

int_duple_dynamic_array_t get_array_from_console();
int parse_input_array(char *str, int_duple_dynamic_array_t *array);
int count_items(char *str);
long long get_number_from_str(char *ch);
int handle_char(char *ch, int_duple_dynamic_array_t *array, int index, int *opening_counter);

#endif //PARSING