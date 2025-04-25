#include <../extras/fixture/src/unity_fixture.h>
#include "support_functions.h"
#include <simple_input.h>
#include <compsets.h>

// First subgroup which contains tests where items swapped in subarrays
/*--------------------------------------------------------------------*/

static int template_first_group_1[] = { 2,    2,  1, 2,   1,  5 };
static int template_first_group_2[] = { 2,    2,  2, 1,   1,  5 };
static int template_first_group_3[] = { 2,    3,  2, 5, 6,   2,  5, 4 };
static int template_first_group_4[] = { 2,    3,  5, 2, 6,   2,  4, 5 };
static int template_first_group_5[] = { 3,    4,  3, 1, 2, 1,   1,  5,   3,  2, 10, 1 };
static int template_first_group_6[] = { 3,    4,  1, 1, 2, 3,   1,  5,   3, 10, 1, 2 };
static int_duple_dynamic_array_t arr1;
static int_duple_dynamic_array_t arr2;

TEST_GROUP(ComparingMultisets_ItemsSwappedInSubarrays);

TEST_SETUP(ComparingMultisets_ItemsSwappedInSubarrays)
{
}

TEST_TEAR_DOWN(ComparingMultisets_ItemsSwappedInSubarrays)
{
}

TEST(ComparingMultisets_ItemsSwappedInSubarrays, Case1)
{
    arr1 = create_DDarray_from_array(&template_first_group_1);
    arr2 = create_DDarray_from_array(&template_first_group_2);
    TEST_ASSERT_TRUE(multisets_are_equal(&arr1, &arr2));
    free_array(&arr1);
    free_array(&arr2);
}

TEST(ComparingMultisets_ItemsSwappedInSubarrays, Case2)
{
    arr1 = create_DDarray_from_array(&template_first_group_3);
    arr2 = create_DDarray_from_array(&template_first_group_4);
    TEST_ASSERT_TRUE(multisets_are_equal(&arr1, &arr2));
    free_array(&arr1);
    free_array(&arr2);
}

TEST(ComparingMultisets_ItemsSwappedInSubarrays, Case3)
{
    arr1 = create_DDarray_from_array(&template_first_group_5);
    arr2 = create_DDarray_from_array(&template_first_group_6);
    TEST_ASSERT_TRUE(multisets_are_equal(&arr1, &arr2));
    free_array(&arr1);
    free_array(&arr2);
}

/*--------------------------------------------------------------------*/
// End first subgroup

// Second subgroup which contains tests where subarrays swapped in array
/*--------------------------------------------------------------------*/

static int template_second_group_1[] = { 2,    2,  2, 1,   1,  5 };
static int template_second_group_2[] = { 2,    1,  5,   2,  2, 1 };
static int template_second_group_3[] = { 2,    2,  4, 5,   3,  2, 5, 6 };
static int template_second_group_4[] = { 2,    3,  2, 5, 6,   2,  4, 5 };
static int template_second_group_5[] = { 3,    1,  5,   4,  1, 1, 2, 3,   3,  2, 10, 1 };
static int template_second_group_6[] = { 3,    4,  1, 1, 2, 3,   1,  5,   3,  2, 10, 1 };
static int_duple_dynamic_array_t arr1;
static int_duple_dynamic_array_t arr2;

TEST_GROUP(ComparingMultisets_SubarraysSwappedInArray);

TEST_SETUP(ComparingMultisets_SubarraysSwappedInArray)
{
}

TEST_TEAR_DOWN(ComparingMultisets_SubarraysSwappedInArray)
{
}

TEST(ComparingMultisets_SubarraysSwappedInArray, Case1)
{
    arr1 = create_DDarray_from_array(&template_second_group_1);
    arr2 = create_DDarray_from_array(&template_second_group_2);
    TEST_ASSERT_TRUE(multisets_are_equal(&arr1, &arr2));
    free_array(&arr1);
    free_array(&arr2);
}

TEST(ComparingMultisets_SubarraysSwappedInArray, Case2)
{
    arr1 = create_DDarray_from_array(&template_second_group_3);
    arr2 = create_DDarray_from_array(&template_second_group_4);
    TEST_ASSERT_TRUE(multisets_are_equal(&arr1, &arr2));
    free_array(&arr1);
    free_array(&arr2);
}

TEST(ComparingMultisets_SubarraysSwappedInArray, Case3)
{
    arr1 = create_DDarray_from_array(&template_second_group_5);
    arr2 = create_DDarray_from_array(&template_second_group_6);
    TEST_ASSERT_TRUE(multisets_are_equal(&arr1, &arr2));
    free_array(&arr1);
    free_array(&arr2);
}

/*--------------------------------------------------------------------*/
// End second subgroup

// Third subgroup which contains tests where different count of subarrays
/*--------------------------------------------------------------------*/

static int template_third_group_1[] = { 2,    2,  2, 1,   1, 5 };
static int template_third_group_2[] = { 2,    1,  5,   1,  2,   1,  1 };
static int template_third_group_3[] = { 2,    3,  2, 5, 6,   2,  4, 5 };
static int template_third_group_4[] = { 2,    2,  4, 5,   2,  2, 5,   1,  6 };
static int template_third_group_5[] = { 3,    1,  5,   4,  1, 1, 2, 3,   3,  2, 10, 1 };
static int template_third_group_6[] = { 3,    2,  1, 1,   2,  2, 3,   1,  5,   3,  2, 10, 1 };
static int_duple_dynamic_array_t arr1;
static int_duple_dynamic_array_t arr2;

TEST_GROUP(ComparingMultisets_DifferentCountOfSubarrays);

TEST_SETUP(ComparingMultisets_DifferentCountOfSubarrays)
{
}

TEST_TEAR_DOWN(ComparingMultisets_DifferentCountOfSubarrays)
{
}

TEST(ComparingMultisets_DifferentCountOfSubarrays, Case1)
{
    arr1 = create_DDarray_from_array(&template_third_group_1);
    arr2 = create_DDarray_from_array(&template_third_group_2);
    TEST_ASSERT_FALSE(multisets_are_equal(&arr1, &arr2));
    free_array(&arr1);
    free_array(&arr2);
}

TEST(ComparingMultisets_DifferentCountOfSubarrays, Case2)
{
    arr1 = create_DDarray_from_array(&template_third_group_3);
    arr2 = create_DDarray_from_array(&template_third_group_4);
    TEST_ASSERT_FALSE(multisets_are_equal(&arr1, &arr2));
    free_array(&arr1);
    free_array(&arr2);
}

TEST(ComparingMultisets_DifferentCountOfSubarrays, Case3)
{
    arr1 = create_DDarray_from_array(&template_third_group_5);
    arr2 = create_DDarray_from_array(&template_third_group_6);
    TEST_ASSERT_FALSE(multisets_are_equal(&arr1, &arr2));
    free_array(&arr1);
    free_array(&arr2);
}

/*--------------------------------------------------------------------*/
// End third subgroup

// Fourth subgroup which contains tests where items swapped between subarrays
/*--------------------------------------------------------------------*/

static int template_fourth_group_1[] = { 2,    2,  2, 5,   1,  1 };
static int template_fourth_group_2[] = { 2,    1,  5,   2,  2, 1 };
static int template_fourth_group_3[] = { 2,    2,  2, 5,   3,  4, 5, 6 };
static int template_fourth_group_4[] = { 2,    3,  2, 5, 6,   2,  4, 5 };
static int template_fourth_group_5[] = { 3,    1,  3,   4,  1, 2, 2, 5,   3,  1, 10, 1 };
static int template_fourth_group_6[] = { 3,    4,  1, 1, 2, 3,   1,  5,   3,  2, 10, 1 };
static int_duple_dynamic_array_t arr1;
static int_duple_dynamic_array_t arr2;

TEST_GROUP(ComparingMultisets_ItemsSwappedBetweenSubarrays);

TEST_SETUP(ComparingMultisets_ItemsSwappedBetweenSubarrays)
{
}

TEST_TEAR_DOWN(ComparingMultisets_ItemsSwappedBetweenSubarrays)
{
}

TEST(ComparingMultisets_ItemsSwappedBetweenSubarrays, Case1)
{
    arr1 = create_DDarray_from_array(&template_fourth_group_1);
    arr2 = create_DDarray_from_array(&template_fourth_group_2);
    TEST_ASSERT_FALSE(multisets_are_equal(&arr1, &arr2));
    free_array(&arr1);
    free_array(&arr2);
}

TEST(ComparingMultisets_ItemsSwappedBetweenSubarrays, Case2)
{
    arr1 = create_DDarray_from_array(&template_fourth_group_3);
    arr2 = create_DDarray_from_array(&template_fourth_group_4);
    TEST_ASSERT_FALSE(multisets_are_equal(&arr1, &arr2));
    free_array(&arr1);
    free_array(&arr2);
}

TEST(ComparingMultisets_ItemsSwappedBetweenSubarrays, Case3)
{
    arr1 = create_DDarray_from_array(&template_fourth_group_5);
    arr2 = create_DDarray_from_array(&template_fourth_group_6);
    TEST_ASSERT_FALSE(multisets_are_equal(&arr1, &arr2));
    free_array(&arr1);
    free_array(&arr2);
}

/*--------------------------------------------------------------------*/
// End fourth subgroup
