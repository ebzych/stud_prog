#include <unity.h>
#include <arrays.h>

void test_NumberBeforeComma_GetNumberFromStr_ReturnNumber() {
    char *str1 = "<123002,";
    char *str2 = "<,";
    char *str3 = " 123002 ,";
    char *str4 = "<  ,";
    char *str5 = "> ,";
    char *str6 = ", 123002 ,";
    TEST_ASSERT_EQUAL_INT32(123002, get_number_from_str(&str1[7]));
    TEST_ASSERT_EQUAL_INT32(-1, get_number_from_str(&str2[1]));
    TEST_ASSERT_EQUAL_INT32(123002, get_number_from_str(&str3[8]));
    TEST_ASSERT_EQUAL_INT32(-1, get_number_from_str(&str4[3]));
    TEST_ASSERT_EQUAL_INT32(-1, get_number_from_str(&str5[2]));
    TEST_ASSERT_EQUAL_INT32(123002, get_number_from_str(&str6[9]));
}

void setUp() {}
void tearDown() {}

int main() {
    UNITY_BEGIN();
    RUN_TEST(test_NumberBeforeComma_GetNumberFromStr_ReturnNumber);
    UNITY_END();
    return 0;
}
