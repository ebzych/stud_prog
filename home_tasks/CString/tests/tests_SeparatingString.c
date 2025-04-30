#include "../../../unity_tests/Unity/extras/fixture/src/unity_fixture.h"
#include <initiator_string.h>
#include <strcmp.h> 
#include <strsub.h>
#include <strsep.h>
#include <stdbool.h>

TEST_GROUP(SeparatingString);

TEST_SETUP(SeparatingString)
{
}

TEST_TEAR_DOWN(SeparatingString)
{
}

TEST(SeparatingString, InputStringWithNeededSymbolReturnCorrectArrayWithSubstrings) {
    string_t string;
    str_init(&string, "Cool string for cool separate function! (bullshit, it so stupid, omg...)");
    char *substrings[] =
        { "Cool", "string", "for", "cool", "separate", "function!", "(bullshit,", "it", "so", "stupid,", "omg...)" };
    strings_array_t *substrings_t = str_sep(&string, ' ');
    bool is_correct = true;
    for (int i = 0; i < substrings_t->size; ++i) {
        printf("\n%s", substrings_t->container[i].str);
        is_correct = is_correct &&
            str_cmp(&substrings_t->container[i], substrings[i]);
    }
    TEST_ASSERT_TRUE(is_correct);
}

TEST(SeparatingString, CharIsNotInStringReturnNull) {

}
