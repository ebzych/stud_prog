#include <unity.h>
#include <compsets.h>
#include <simple_input.h>
#include <stdbool.h>

void setUp() {}
void tearDown() {}

// void test__CountItems_NumberElementsFromString() {
//     char *str1 = "<2,1>";
//     char *str2 = "<2       1>";
//     char *str3 = "<2<,1>,<1>>";
//     char *str4 = "<,1>";
//     char *str5 = "<< ,1>,<1>>";
//     char *str6 = "<   2  ,  1   >";
//     TEST_ASSERT_EQUAL(2, count_items(str1));
//     TEST_ASSERT_EQUAL(-1, count_items(str2));
//     TEST_ASSERT_EQUAL(-1, count_items(str3));
//     TEST_ASSERT_EQUAL(-1, count_items(str4));
//     TEST_ASSERT_EQUAL(-1, count_items(str5));
//     TEST_ASSERT_EQUAL(2, count_items(str6));
// }

// void test__ParseInputArray_CorrectWriteIntoArray() {
//     // initialization template array
//     int_duple_dynamic_array_t *arr = malloc(sizeof(int_duple_dynamic_array_t));

//     // initialization test strings for parsing
//     char *str1 = "<<2,1>,<1>>";
//     char *str2 = "<   < 2 ,     1 > ,    < 1 >    >";
//     char *str3 = "<2<,1>,<1>>";
//     char *str4 = "<<,1>,<1>>";
//     char *str5 = "<< ,1>,<1>>";
//     char *str6 = "<<2,1>,<1";
//     char *str7 = "<<2 1><1>>";
    
//     // tests
//     int result;
//     if (parse_input_array(str1, arr) != -1) {}
//     // check_duple_array();
// }

// void test_NumberBeforeCommaOrIncorrectInput_GetNumberFromStr_ReturnNumberOrError() {
//     char *str1 = "<123002,";
//     char *str2 = "<,";
//     char *str3 = " 123002 ,";
//     char *str4 = "<  ,";
//     char *str5 = "> ,";
//     char *str6 = ", 123002 ,";
//     TEST_ASSERT_EQUAL_INT32(123002, get_number_from_str(&str1[7]));
//     TEST_ASSERT_EQUAL_INT32(SMALLEST_LLONG, get_number_from_str(&str2[1]));
//     TEST_ASSERT_EQUAL_INT32(123002, get_number_from_str(&str3[8]));
//     TEST_ASSERT_EQUAL_INT32(SMALLEST_LLONG, get_number_from_str(&str4[3]));
//     TEST_ASSERT_EQUAL_INT32(SMALLEST_LLONG, get_number_from_str(&str5[2]));
//     TEST_ASSERT_EQUAL_INT32(123002, get_number_from_str(&str6[9]));
// }

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

bool check_trivial_duple_array(int_duple_dynamic_array_t *array) {
    int arr[3];

    // add element to 'arr[]'
    int ind = 0;
    for (int i = 0; i < array->size; i++) {
        for (int j = 0; j < array->container[i].size; j++) {
            // check that '2' belong in subarray with size 2
            if (array->container[i].container[j] == 2) {
                if (array->container[i].size != 2) {
                    return false;
                }
            }

            arr[ind] = array->container[i].container[j];
            ind++;
        }
    }

    // special comparator
    int comp_int(const void* a, const void* b)
        { return *(int *)a < *(int *)b ? -1 : 1; }

    qsort(&arr, sizeof(arr) / sizeof(int), sizeof(int), comp_int);

    // compare content array
    int expected[] = { 1, 1, 2 };
    for (int i = 0; i < 3; i++) {
        if (arr[i] != expected[i])
            { return false; }
    }

    return true;
}

void test_CreateDDArrayFromArray_InputTrivialArray_ReturnCorrect() {
    int_duple_dynamic_array_t arr;
    int template_arr[] = { 2, 2, 2, 1, 1, 1 };
    arr = create_DDarray_from_array(template_arr);
    TEST_ASSERT_TRUE(check_trivial_duple_array(&arr));
}

int main() {
    UNITY_BEGIN();
    RUN_TEST(test_CreateDDArrayFromArray_InputTrivialArray_ReturnCorrect);
    // RUN_TEST(test_NumberBeforeCommaOrIncorrectInput_GetNumberFromStr_ReturnNumberOrError);
    // RUN_TEST(test__CountItems_NumberElementsFromString);
    UNITY_END();
    return 0;
}
