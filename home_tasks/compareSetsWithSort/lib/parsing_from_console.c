#include <parsing_from_console.h>

int parse_input_array(char *str, int_duple_dynamic_array_t *array) {
    int str_len = strlen(str);
    int openning_counter = 0; // must be on 0 or 1 position
    // iterations are made after first '<' and before last '>'
    for (int i = 1;
         (i + 1 < str_len) && (openning_counter == 0 || openning_counter == 1); // if -1, hence excess '>', if 2, hence excess '<'
         i++)
    {
        if (handle_char(&str[i], array, i, &openning_counter) == -1)
            { return -1; }
    }

    if (openning_counter != 0)  // hence incorrect combination of opened and closed branches
        { return -1; }
    else
        { return 0; }
}

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
