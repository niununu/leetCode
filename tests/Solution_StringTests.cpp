#include <catch2/catch_test_macros.hpp>
#include "../include/Solution_String.h"
#include "SolutionTestUtil.h"
 class SolutionStringTestsFixture
 {
 public:
     SolutionStringTestsFixture()
     {
         so = Solution();
     }
     Solution so;
     int expectResult{ 0 };
 }; // class SolutionTestsFixture

TEST_CASE_METHOD(SolutionStringTestsFixture, "reverseString", "[reverseString]""[Solution_StringTests]")
{
    std::vector<char> input;
    std::vector<char> output;

    SECTION("1")
    {
        input = {'h','e','l','l','o'};
        output = {'o','l','l','e','h'};
    }
    SECTION("2")
    {
        input = {'H','a','n','n','a','h'};
        output = {'h','a','n','n','a','H'};
    }
    SECTION("3")
    {
        input = {'H'};
        output = {'H'};
    }
    SECTION("4")
    {
        input = {'H', ' '};
        output = {' ','H'};
    }
    so.reverseString(input);
    REQUIRE(SolutionTestUtil::isSameVector(input, output));
}

TEST_CASE_METHOD(SolutionStringTestsFixture, "reverse", "[reverse]""[Solution_StringTests]")
{
    int input = 0;
    int output = 0;
    SECTION("1")
    {
        input = 123;
        output = 321;
    }

    SECTION("2")
    {
        input = -123;
        output = -321;
    }

    SECTION("3")
    {
        input = 0;
        output = 0;
    }

    SECTION("4")
    {
        input = -1;
        output = -1;
    }
    SECTION("5")
    {
        input = 120;
        output = 21;
    }
    REQUIRE(so.reverse(input) == output);
}

TEST_CASE_METHOD(SolutionStringTestsFixture, "firstUniqChar", "[firstUniqChar]""[Solution_StringTests]")
{
    std::string input;
    int output;
    SECTION("1")
    {
        input = "leetcode";
        output = 0;
    }
    SECTION("2")
    {
        input = "loveleetcode";
        output = 2;
    }
    SECTION("3")
    {
        input = "lloo";
        output = -1;
    }
    REQUIRE(so.firstUniqChar(input) == output);
}

TEST_CASE_METHOD(SolutionStringTestsFixture, "isAnagram", "[isAnagram]""[Solution_StringTests]")
{
    std::string input1;
    std::string input2;
    bool output = true;
    SECTION("1")
    {
        input1 = "anagram";
        input2 = "nagaram";
        output = true;
    }
    SECTION("2")
    {
        input1 = "rat";
        input2 = "car";
        output = false;
    }
    SECTION("3")
    {
        input1 = "rat";
        input2 = "r";
        output = false;
    }    REQUIRE(so.isAnagram(input1, input2) == output);
}

TEST_CASE_METHOD(SolutionStringTestsFixture, "isPalindrome", "[isPalindrome]""[Solution_StringTests]")
{
    string input = "";
    bool result = false;
    SECTION("1")
    {
        input = "A man, a plan, a canal: Panama";
        result = true;
    }
    SECTION("2")
    {
        input ="race a car";
        result = false;
    }
    SECTION("3")
    {
        input ="";
        result = true;
    }
    SECTION("4")
    {
        input ="A0123 man, a plan, a canal: Panam3210a";
        result = true;
    }
    REQUIRE(so.isPalindrome(input) == result);
}

TEST_CASE_METHOD(SolutionStringTestsFixture, "myAtoi", "[myAtoi]""[Solution_StringTests]")
{
    string input = "";
    int result = 0;
    SECTION("1")
    {
        input = "42";
        result = 42;
    }

    SECTION("2")
    {
        input = "   -42";
        result = -42;
    }

    SECTION("3")
    {
        input = "4193 with words";
        result = 4193;
    }
    SECTION("4")
    {
        input = "words and 987";
        result = 0;
    }
    SECTION("5")
    {
        input = "-91283472332";
        result = -2147483648;
    }
    SECTION("6")
    {
        input = "91283472332";
        result = 2147483647;
    }
    SECTION("7")
    {
        input = "+-12";
        result = 0;
    }
    SECTION("8")
    {
        input = "2147483646";
        result = 2147483646;
    }
    REQUIRE(so.myAtoi(input) == result);
}

TEST_CASE_METHOD(SolutionStringTestsFixture, "longestCommonPrefix", "[longestCommonPrefix]""[Solution_StringTests]")
{
    vector<string> input;
    string result;
    SECTION("1")
    {
        input = {"flower","flow","flight"};
        result = "fl";
    }

    SECTION("2")
    {
        input = {"dog","racecar","car"};
        result = "";
    }

    SECTION("3")
    {
        input = {"d","dd","ddd"};
        result = "d";
    }
    REQUIRE(so.longestCommonPrefix(input) == result);
}