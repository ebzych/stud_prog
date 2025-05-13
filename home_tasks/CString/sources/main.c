#include <stdio.h>
#include <string_t.h>
#include <time.h>

int main() {
    char *big_string = NULL;
    big_string = create_big_string(1000000);
    time_t time_start = time(NULL);
    strings_array_t *arr = str_sep(big_string, ' ');
    time_t time_end = time(NULL);
    printf("\noperatrion: separating string by character,\
        \nstring_size: 1_000_000,\
        \nexec_time: %lf\n", \
        difftime(time_end, time_start));
    free(big_string);
    free_str_arr(arr);
    return 0;
}
