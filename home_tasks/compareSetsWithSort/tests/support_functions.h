#ifndef SUPPORTFUNC
#define SUPPORTFUNC

#include <arrays.h>
#include <stdbool.h>

int_duple_dynamic_array_t *create_array();
int comp_int(const void* a, const void* b);         // special comparator
bool check_trivial_duple_array(int_duple_dynamic_array_t *array);

#endif //SUPPORTFUNC