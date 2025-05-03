#include "initiator_string.h"
#include "strlrchr.h"

char *strchr_ccp(const char *cstring, char ch) {
    const char *res = cstring;
    while (*res != ch && *res != '\0') {
        ++res;
    }
    if (res == cstring) {
        res = NULL;
    }
    return (char *)res;
}

char *strchr_sp(string_t *string, char ch) {
    return strchr_ccp(string->str, ch);
}

char *strchr_cp(char *cstring, char ch) {
    return strchr_ccp(cstring, ch);
}

char *strrchr_ccp(const char *cstring, char ch) {
    const char *ptr = cstring, *res = NULL;
    while (*ptr != '\0') {
        if (*ptr == ch) {
            res = ptr;
        }
        ++ptr;
    }
    return (char *)res;
}

char *strrchr_sp(string_t *string, char ch) {
    return strrchr_ccp(string->str, ch);
}

char *strrchr_cp(char *cstring, char ch) {
    return strrchr_ccp(cstring, ch);
}
