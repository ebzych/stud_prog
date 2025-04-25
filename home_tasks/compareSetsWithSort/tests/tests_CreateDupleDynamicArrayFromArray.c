#include <../extras/fixture/src/unity_fixture.h>
#include "support_functions.h"
#include <parsing_from_console.h>
#include <simple_input.h>


static int_duple_dynamic_array_t arr;
static int template_arr[] = { 2,   2, 2,1,  1, 1 };


TEST_GROUP(CreateDupleDynamicArrayFromArray);


TEST_SETUP(CreateDupleDynamicArrayFromArray) {
    arr = create_DDarray_from_array(&template_arr);
}

TEST_TEAR_DOWN(CreateDupleDynamicArrayFromArray)
{
}


TEST(CreateDupleDynamicArrayFromArray, InputTrivialArray_ReturnCorrect) {
    TEST_ASSERT_TRUE(check_trivial_duple_array(&arr));
}
