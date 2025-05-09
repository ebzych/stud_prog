#ifndef STRLRCHR
#define STRLRCHR

typedef struct string_s string_t;
typedef struct strings_array_s strings_array_t;
#include "string_t.h"

#define str_chr(string, ch) _Generic( (string), \
        string_t *      : strchr_sp,             \
        const char *    : strchr_ccp,             \
        char *          : strchr_cp                \
    )(string, ch)

char *strchr_sp(string_t *string, char ch);
char *strchr_ccp(const char *cstring, char ch);
char *strchr_cp(char *cstring, char ch);
    
#define str_rchr(string, ch) _Generic( (string), \
        string_t *      : strrchr_sp,             \
        const char *    : strrchr_ccp,             \
        char *          : strrchr_cp                \
    )(string, ch)

char *strrchr_sp(string_t *string, char ch);
char *strrchr_ccp(const char *cstring, char ch);
char *strrchr_cp(char *cstring, char ch);

#endif  //STRLRCHR