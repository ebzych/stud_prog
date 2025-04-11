#include <parsing_from_console.h>

int handle_char(char *ch, int_duple_dynamic_array_t *array, int index, int *opening_counter) {
    switch (ch[0])
    {
    case '<':
        opening_counter++;
        if (init_subarray(ch, array, index) == -1)
            { return -1; }
        break;

    case '>':
        opening_counter--;
        array->size++;
        break;

    default:                    //////////////////////////////////////
    }
}

// 'str' is string which begining at ','
// function reverse for take number before ','
int get_number_from_str(char *ch) {
    do { ch--; } while (*ch == ' ');

    int number = 0;
    int digit = 0;
    while (*ch >= '0' && *ch <= '9') {
        number += (*ch - '0') * pow(10, digit);
        ch--;
        digit++;
    }

    if (digit != 0 && (*ch == '<' || *ch == ',' || *ch == ' '))
        { return number; }
    else
        { return -1; }
}

int count_items(char *str) {
    int count = 1; // number of items one greater than number of ','
    int len_str = strlen(str);
    for (char *ch = str; (*ch != '>') && (*ch != '\0'); ch++) {
        if (*ch == ',')
            { count++; }
    }

    if (str[len_str - 1] != '>')
        { return -1; }

    if (str[1] == '>')
        { return 0; }

    return count;
}
