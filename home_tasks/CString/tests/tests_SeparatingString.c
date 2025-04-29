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
    string_t *substrings_t = str_sep(string, ' ');
    bool is_correct = true;
    for (int i = 0; i < sizeof(substrings) / sizeof(char *); ++i) {
        is_correct = str_cmp(&substrings_t[i], substrings[i]);
    }
    TEST_ASSERT_TRUE(is_correct);
}

TEST(SeparatingString, CharIsNotInStringReturnNull) {

}
