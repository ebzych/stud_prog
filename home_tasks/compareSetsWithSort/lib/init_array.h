#ifndef INCONSOLE
#define INCONSOLE

#include <compsets.h>
#include <includes.h>
#include <arrays.h>

int_dynamic_array_t *get_subarray(int_duple_dynamic_array_t *array, int index);
int count_items(char *str);
int realloc_container(int_duple_dynamic_array_t *array);
int alloc_subarray(char *str, int_duple_dynamic_array_t *array, int index_subarray);
int get_number_from_str(char *ch);
int init_subarray(char *str, int_duple_dynamic_array_t *array, int index);
int handle_char(char *ch, int_duple_dynamic_array_t *array, int index, int *opening_counter);

#endif //INCONSOLE
