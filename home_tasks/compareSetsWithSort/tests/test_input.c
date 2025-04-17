#include <unity.h>
#include <compsets.h>
#include <simple_input.h>
#include <stdbool.h>
#include <arrays.h>
#include "support_functions.h"

void setUp() {}
void tearDown() {}

/*
void test__CountItems_NumberElementsFromString() {
    char *str1 = "<2,1>";
    char *str2 = "<2       1>";
    char *str3 = "<2<,1>,<1>>";
    char *str4 = "<,1>";
    char *str5 = "<< ,1>,<1>>";
    char *str6 = "<   2  ,  1   >";
    TEST_ASSERT_EQUAL(2, count_items(str1));
    TEST_ASSERT_EQUAL(-1, count_items(str2));
    TEST_ASSERT_EQUAL(-1, count_items(str3));
    TEST_ASSERT_EQUAL(-1, count_items(str4));
    TEST_ASSERT_EQUAL(-1, count_items(str5));
    TEST_ASSERT_EQUAL(2, count_items(str6));
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
    
    // tests
    int result;
    if (parse_input_array(str1, arr) != -1) {}
    // check_duple_array();
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
    */

void test_CreateDDArrayFromArray_InputTrivialArray_ReturnCorrect() {
    int_duple_dynamic_array_t arr;
    int template_arr[] = { 2,        2, 2,1,  1, 1 };
    arr = create_DDarray_from_array(template_arr);
    TEST_ASSERT_TRUE(check_trivial_duple_array(&arr));
}

void test_MultisetsAreEqual_ItemsSwappedInSubarrays_True() {
    int template_1[] = { 2,    2,  2,1,  1, 5 };
    int template_2[] = { 2,    2,  1,2,  1, 5 };
    int_duple_dynamic_array_t arr1 = create_DDarray_from_array(template_1);
    int_duple_dynamic_array_t arr2 = create_DDarray_from_array(template_2);
    TEST_ASSERT_TRUE(multisets_are_equal(&arr1, &arr2));

    int template_3[] = { 2,    3,  2,5,6,  2, 5,4 };
    int template_4[] = { 2,    3,  5,2,6,  2, 4,5 };
    arr1 = create_DDarray_from_array(template_3);
    arr2 = create_DDarray_from_array(template_4);
    TEST_ASSERT_TRUE(multisets_are_equal(&arr1, &arr2));

    int template_5[] = { 3,    4,  3,1,2,1,  1, 5,   3,  2,10,1 };
    int template_6[] = { 3,    4,  1,1,2,3,  1, 5,    3,  10,1,2 };
    arr1 = create_DDarray_from_array(template_5);
    arr2 = create_DDarray_from_array(template_6);
    TEST_ASSERT_TRUE(multisets_are_equal(&arr1, &arr2));

    free_array(&arr1);
    free_array(&arr2);
}

void test_MultisetsAreEqual_SubarraysSwappedInArray_True() {
    int template_1[] = { 2,    2,  2,1,  1, 5 };
    int template_2[] = { 2,    1, 5,    2,  2,1 };
    int_duple_dynamic_array_t arr1 = create_DDarray_from_array(&template_1);
    int_duple_dynamic_array_t arr2 = create_DDarray_from_array(&template_2);
    TEST_ASSERT_TRUE(multisets_are_equal(&arr1, &arr2));

    int template_3[] = { 2,    2, 4,5,    3,  2,5,6 };
    int template_4[] = { 2,    3,  2,5,6,  2, 4,5 };
    arr1 = create_DDarray_from_array(&template_3);
    arr2 = create_DDarray_from_array(&template_4);
    TEST_ASSERT_TRUE(multisets_are_equal(&arr1, &arr2));

    int template_5 = { 3,    1, 5,    4,  1,1,2,3,   3,  2,10,1 };
    int template_6 = { 3,    4,  1,1,2,3,  1, 5,    3,  2,10,1 };
    arr1 = create_DDarray_from_array(&template_5);
    arr2 = create_DDarray_from_array(&template_6);
    TEST_ASSERT_TRUE(multisets_are_equal(&arr1, &arr2));

    free_array(&arr1);
    free_array(&arr2);
}

void test_MultisetsAreEqual_DifferentCountOfSubarrays_False() {
    int template_1[] = { 2,    2,  2,1,  1, 5 };
    int template_2[] = { 2,    1, 5,    1,  2,  1,  1 };
    int_duple_dynamic_array_t arr1 = create_DDarray_from_array(&template_1);
    int_duple_dynamic_array_t arr2 = create_DDarray_from_array(&template_2);
    TEST_ASSERT_FALSE(multisets_are_equal(&arr1, &arr2));

    int template_3[] = { 2,    3,  2,5,6,  2, 4,5 };
    int template_4[] = { 2,    2, 4,5,    2,  2,5,  1, 6 };
    arr1 = create_DDarray_from_array(&template_3);
    arr2 = create_DDarray_from_array(&template_4);
    TEST_ASSERT_FALSE(multisets_are_equal(&arr1, &arr2));

    int template_5[] = { 3,    1, 5,    4,  1,1,2,3,   3,  2,10,1 };
    int template_6[] = { 3,    2,  1,1,   2,  2,3,  1, 5,    3,  2,10,1 };
    arr1 = create_DDarray_from_array(&template_5);
    arr2 = create_DDarray_from_array(&template_6);
    TEST_ASSERT_FALSE(multisets_are_equal(&arr1, &arr2));

    free_array(&arr1);
    free_array(&arr2);
}

void test_MultisetsAreEqual_ItemsSwappedBetweenSubarrays_False() {
    int template_1[] = { 2,    2,  2,5,  1, 1 };
    int template_2[] = { 2,    1, 5,    2,  2,1 };
    int_duple_dynamic_array_t arr1 = create_DDarray_from_array(&template_1);
    int_duple_dynamic_array_t arr2 = create_DDarray_from_array(&template_2);
    TEST_ASSERT_FALSE(multisets_are_equal(&arr1, &arr2));

    int template_3[] = { 2,    2, 2,5,    3,  4,5,6 };
    int template_4[] = { 2,    3,  2,5,6,  2, 4,5 };
    arr1 = create_DDarray_from_array(&template_3);
    arr2 = create_DDarray_from_array(&template_4);
    TEST_ASSERT_FALSE(multisets_are_equal(&arr1, &arr2));

    int template_5[] = { 3,    1, 3,    4,  1,2,2,5,   3,  1,10,1 };
    int template_6[] = { 3,    4,  1,1,2,3,  1, 5,    3,  2,10,1 };
    arr1 = create_DDarray_from_array(&template_5);
    arr2 = create_DDarray_from_array(&template_6);
    TEST_ASSERT_FALSE(multisets_are_equal(&arr1, &arr2));

    free_array(&arr1);
    free_array(&arr2);
}

int main() {
    UNITY_BEGIN();
    RUN_TEST(test_CreateDDArrayFromArray_InputTrivialArray_ReturnCorrect);
    RUN_TEST(test_MultisetsAreEqual_DifferentCountOfSubarrays_False);
    RUN_TEST(test_MultisetsAreEqual_ItemsSwappedBetweenSubarrays_False);
    RUN_TEST(test_MultisetsAreEqual_ItemsSwappedInSubarrays_True);
    RUN_TEST(test_MultisetsAreEqual_SubarraysSwappedInArray_True);
    // RUN_TEST(test_NumberBeforeCommaOrIncorrectInput_GetNumberFromStr_ReturnNumberOrError);
    // RUN_TEST(test__CountItems_NumberElementsFromString);
    UNITY_END();
    return 0;
}
