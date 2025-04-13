#ifndef INCONSOLE
#define INCONSOLE

#include <arrays.h>
#include <parsing_from_console.h>

static const long long SMALLEST_LLONG = -9223372036854775807;

int realloc_container(int_duple_dynamic_array_t *array);
int alloc_subarray(char *str, int_duple_dynamic_array_t *array, int index_subarray);
int init_subarray(char *str, int_duple_dynamic_array_t *array, int index);

#endif //INCONSOLE
