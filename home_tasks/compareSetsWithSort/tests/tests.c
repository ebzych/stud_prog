#include <../extras/fixture/src/unity_fixture.h>
#include <compsets.h>
#include <simple_input.h>
#include <stdbool.h>
#include <arrays.h>
#include "support_functions.h"


void run_all_tests() {
    RUN_TEST_GROUP(CreateDupleDynamicArrayFromArray);
    RUN_TEST_GROUP(ComparingMultisets_ItemsSwappedInSubarrays);
    RUN_TEST_GROUP(ComparingMultisets_SubarraysSwappedInArray);
    RUN_TEST_GROUP(ComparingMultisets_DifferentCountOfSubarrays);
    RUN_TEST_GROUP(ComparingMultisets_ItemsSwappedBetweenSubarrays);
}

int main(int argc, const char *argv[]) {
    return UnityMain(argc, argv, run_all_tests);
}

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