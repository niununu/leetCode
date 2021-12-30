#include <catch2/catch_test_macros.hpp>
#include "../include/Solution.h"

class SolutionTestsFixture
{
public:
    SolutionTestsFixture()
    {
        so = Solution();
    }
    Solution so;
    std::vector<int> input;
    std::vector<int> input2;
    std::vector<int> output;
    int expectResult{ 0 };
}; // class SolutionTestsFixture

TEST_CASE_METHOD(SolutionTestsFixture, "isUnique", "[isUnique]""[Solution]")
{
    REQUIRE(so.isUnique("leetcode") == false);
    REQUIRE(so.isUnique("abc") == true);
    REQUIRE(so.isUnique("abccd") == false);
    REQUIRE(so.isUnique("a") == true);
    REQUIRE(so.isUnique("aA") == true);
    REQUIRE(so.isUnique("aAbb") == false);
}

TEST_CASE_METHOD(SolutionTestsFixture, "3.lengthOfLongestSubstring", "[lengthOfLongestSubstring]""[Solution]")
{
    REQUIRE(so.lengthOfLongestSubstring("abcabcbb") == 3);
    REQUIRE(so.lengthOfLongestSubstring("bbbbb") == 1);
    REQUIRE(so.lengthOfLongestSubstring("pwwkew") == 3);
    REQUIRE(so.lengthOfLongestSubstring("") == 0);
    REQUIRE(so.lengthOfLongestSubstring("dasfd") == 4);
    REQUIRE(so.lengthOfLongestSubstring("dasghuyt") == 8);
    REQUIRE(so.lengthOfLongestSubstring("aaasghuyt") == 7);
    REQUIRE(so.lengthOfLongestSubstring("jbpnbwwd") == 4);

}


