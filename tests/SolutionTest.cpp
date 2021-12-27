#include <catch2/catch_test_macros.hpp>
#include "../include/Solution.h"

TEST_CASE("isUnique", "[isUnique]")
{
    Solution so;
    REQUIRE(so.isUnique("leetcode") == false);
    REQUIRE(so.isUnique("abc") == true);
    REQUIRE(so.isUnique("abccd") == false);
    REQUIRE(so.isUnique("a") == true);
    REQUIRE(so.isUnique("aA") == true);
    REQUIRE(so.isUnique("aAbb") == false);
}

TEST_CASE("3.lengthOfLongestSubstring", "[lengthOfLongestSubstring]")
{
    Solution so;
    REQUIRE(so.lengthOfLongestSubstring("abcabcbb") == 3);
    REQUIRE(so.lengthOfLongestSubstring("bbbbb") == 1);
    REQUIRE(so.lengthOfLongestSubstring("pwwkew") == 3);
    REQUIRE(so.lengthOfLongestSubstring("") == 0);
    REQUIRE(so.lengthOfLongestSubstring("dasfd") == 4);
    REQUIRE(so.lengthOfLongestSubstring("dasghuyt") == 8);
    REQUIRE(so.lengthOfLongestSubstring("aaasghuyt") == 7);
    REQUIRE(so.lengthOfLongestSubstring("jbpnbwwd") == 4);

}