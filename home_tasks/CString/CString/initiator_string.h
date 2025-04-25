#ifndef INIT_STR
#define INIT_STR

#include "string_t.h"
#include <stdlib.h>

void init_string_spccp(string_t *to, const char *from);
void init_string_spsp(string_t *to, string_t *from);
void init_string_sps(string_t *to, string_t from);
size_t strlen(const char *string);

#endif //INIT_STR
