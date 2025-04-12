#include <unity.h>
#include <compsets.h>
#include <parsing_from_console.h>

int compare_duple_dynamic_arrays(int_duple_dynamic_array_t *first,
                                    int_duple_dynamic_array_t *second) {
    if (first->size != second->size)
        { return -1; }

    for (int i = 0; i < first->size; i++) {
        for (int j = 0; j < first->container[i].size; j++){
            if (j < second->container[i].size &&
                (first->container[i].container[j] !=
                second->container[i].container[j]) )
                { return -1; }
        }
    }

    return 0;
}

int_duple_dynamic_array_t *create_array() {
    int_duple_dynamic_array_t *arr;
    arr->size = 2;
    arr->container =
        malloc(arr->size * sizeof(int_duple_dynamic_array_t *));
    arr->container[0].size = 2;
    arr->container[0].container =
        malloc(arr->container[0].size * sizeof(int_dynamic_array_t *));
    arr->container[1].container =
        malloc(sizeof(int_dynamic_array_t *));
    arr->container[0].container[0] = 2;
    arr->container[0].container[1] = 1;
    arr->container[1].container[0] = 1;
    return arr;
}

void test__ParseInputArray_CorrectWriteIntoArray() {
    // initialization template array
    int_duple_dynamic_array_t *arr = malloc(sizeof(int_duple_dynamic_array_t));

    // initialization test strings for parsing
    char *str1 = "<<2,1>,<1>>";
    char *str2 = "<   < 2 ,     1 > ,    < 1 >    >";
    char *str3 = "<2<,1>,<1>>";
    char *str4 = "<<,1>,<1>>";
    char *str5 = "<< ,1>,<1>>";
    char *str6 = "<<2,1>,<1";
    char *str7 = "<<2 1><1>>";
    
}

void test_NumberBeforeCommaOrIncorrectInput_GetNumberFromStr_ReturnNumberOrError() {
    char *str1 = "<123002,";
    char *str2 = "<,";
    char *str3 = " 123002 ,";
    char *str4 = "<  ,";
    char *str5 = "> ,";
    char *str6 = ", 123002 ,";
    TEST_ASSERT_EQUAL_INT32(123002, get_number_from_str(&str1[7]));
    TEST_ASSERT_EQUAL_INT32(SMALLEST_LLONG, get_number_from_str(&str2[1]));
    TEST_ASSERT_EQUAL_INT32(123002, get_number_from_str(&str3[8]));
    TEST_ASSERT_EQUAL_INT32(SMALLEST_LLONG, get_number_from_str(&str4[3]));
    TEST_ASSERT_EQUAL_INT32(SMALLEST_LLONG, get_number_from_str(&str5[2]));
    TEST_ASSERT_EQUAL_INT32(123002, get_number_from_str(&str6[9]));
}

void setUp() {}
void tearDown() {}

int main() {
    UNITY_BEGIN();
    RUN_TEST(test_NumberBeforeCommaOrIncorrectInput_GetNumberFromStr_ReturnNumberOrError);
    UNITY_END();
    return 0;
}
