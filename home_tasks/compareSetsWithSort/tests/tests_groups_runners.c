#include <../extras/fixture/src/unity_fixture.h>


//  Runner for function which create multiset from array
TEST_GROUP_RUNNER(CreateDupleDynamicArrayFromArray) {
    RUN_TEST_CASE(CreateDupleDynamicArrayFromArray, InputTrivialArray_ReturnCorrect);
}

/*--------------------------------------------------------------------*/
//  Runners for multisets comparing function
/*--------------------------------------------------------------------*/

/*--------------------------------------------------------------------*/

//  Runner for subgroup which contains tests where items swapped in subarrays
TEST_GROUP_RUNNER(ComparingMultisets_ItemsSwappedInSubarrays) {
    RUN_TEST_CASE(ComparingMultisets_ItemsSwappedInSubarrays, Case1);
    RUN_TEST_CASE(ComparingMultisets_ItemsSwappedInSubarrays, Case2);
    RUN_TEST_CASE(ComparingMultisets_ItemsSwappedInSubarrays, Case3);
}

/*--------------------------------------------------------------------*/

//  Runner for subgroup which contains tests where subarrays swapped in array
TEST_GROUP_RUNNER(ComparingMultisets_SubarraysSwappedInArray) {
    RUN_TEST_CASE(ComparingMultisets_SubarraysSwappedInArray, Case1);
    RUN_TEST_CASE(ComparingMultisets_SubarraysSwappedInArray, Case2);
    RUN_TEST_CASE(ComparingMultisets_SubarraysSwappedInArray, Case3);
}

/*--------------------------------------------------------------------*/

//  Runner for subgroup which contains tests where different count of subarrays
TEST_GROUP_RUNNER(ComparingMultisets_DifferentCountOfSubarrays) {
    RUN_TEST_CASE(ComparingMultisets_DifferentCountOfSubarrays, Case1);
    RUN_TEST_CASE(ComparingMultisets_DifferentCountOfSubarrays, Case2);
    RUN_TEST_CASE(ComparingMultisets_DifferentCountOfSubarrays, Case3);
}

/*--------------------------------------------------------------------*/

//  Runner for subgroup which contains tests where items swapped between subarrays
TEST_GROUP_RUNNER(ComparingMultisets_ItemsSwappedBetweenSubarrays) {
    RUN_TEST_CASE(ComparingMultisets_ItemsSwappedBetweenSubarrays, Case1);
    RUN_TEST_CASE(ComparingMultisets_ItemsSwappedBetweenSubarrays, Case2);
    RUN_TEST_CASE(ComparingMultisets_ItemsSwappedBetweenSubarrays, Case3);
}
