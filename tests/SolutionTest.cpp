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

template <class T>
bool isSameVector(std::vector<T> vec1, std::vector<T> vec2)
{
    bool isSame = true;
    if (vec1.size() != vec2.size())
    {
        isSame = false;
    }
    else
    {
        for (int i = 0; i < vec1.size(); ++i)
        {
            if (vec1[i] != vec2[i])
            {
                isSame = false;
                break;
            }
        }
    }
    return isSame;
}

TEST_CASE("removeDuplicates", "[removeDuplicates]")
{
    Solution so;
    std::vector<int> input;
    std::vector<int> output;
    SECTION("1")
    {
        input = { 1,1,2 };
        output = {1, 2};
    }

    SECTION("2")
    {
        input = {0,0,1,1,1,2,2,3,3,4};
        output = {0,1,2,3,4};
    }

    SECTION("3")
    {
        input = {};
        output = {};
    }

    SECTION("4")
    {
        input = {1,1,1};
        output = {1};
    }

    SECTION("5")
    {
        input = {1};
        output = {1};
    }
    REQUIRE(so.removeDuplicates(input) == output.size());
    REQUIRE(isSameVector(input, output));
}

TEST_CASE("maxProfit", "[maxProfit]")
{
    Solution so;
    std::vector<int> prices;
    int expectResult = 0;
    SECTION("1")
    {
        prices = {1,2,3,4};
        expectResult = 3;
    }

    SECTION("2")
    {
        prices = {7,1,5,3,6,4};
        expectResult = 7;
    }

    SECTION("3")
    {
        prices = {1,2,3,4,5};
        expectResult = 4;
    }
    SECTION("4")
    {
        prices = {7,6,4,3,1};
        expectResult = 0;
    }
    SECTION("5")
    {
        prices = {7};
        expectResult = 0;
    }
    SECTION("6")
    {
        prices = {1, 1};
        expectResult = 0;
    }
    SECTION("7")
    {
        prices = {1, 7};
        expectResult = 6;
    }
    SECTION("8")
    {
        prices = {6,1,3,2,4,7};
        expectResult = 7;
    }
    REQUIRE(so.maxProfit(prices) == expectResult);
}

TEST_CASE("rotate", "[rotate]")
{
    Solution so;
    std::vector<int> input;
    std::vector<int> output;
    int k = 0;
    SECTION("1")
    {
        input = {1,2,3,4,5,6,7};
        output = {5,6,7,1,2,3,4};
        k = 3;
    }
    SECTION("2")
    {
        input = {-1,-100,3,99};
        output = {3,99,-1,-100};
        k = 2;
    }
    SECTION("3")
    {
        input = {-1,-100,3,99};
        output = {-1,-100,3,99};
        k = 0;
    }
    SECTION("4")
    {
        input = {1,2,3,4,5,6,7};
        output = {1,2,3,4,5,6,7};
        k = 7;
    }
    SECTION("5")
    {
        input = {1,2,3,4,5,6,7};
        output = {7,1,2,3,4,5,6};
        k = 8;
    }
    SECTION("5")
    {
        input = {1,2,3,4};
        output = {1,2,3,4};
        k = 8;
    }
    SECTION("5")
    {
        input = {1,2,3,4};
        output = {4,1,2,3};
        k = 9;
    }
    so.rotate(input, k);
    REQUIRE(isSameVector(input, output));
}

TEST_CASE("containsDuplicate", "[containsDuplicate]")
{
    Solution so;
    vector<int> input;
    REQUIRE(so.containsDuplicate(input) == false);
    input = {1};
    REQUIRE(so.containsDuplicate(input) == false);
    input = {1,2,3,1};
    REQUIRE(so.containsDuplicate(input) == true);
    input = {1,2,3,4};
    REQUIRE(so.containsDuplicate(input) == false);
    input = {1,1,1,3,3,4,3,2,4,2};
    REQUIRE(so.containsDuplicate(input) == true);
}

TEST_CASE("singleNumber", "[singleNumber]")
{
    Solution so;
    vector<int> input;
    int result = 0;
    SECTION("1")
    {
        input = {2,2,1};
        result = 1;
    }
    SECTION("2")
    {
        input = {4,1,2,1,2};
        result = 4;
    }
    REQUIRE(so.singleNumber(input) == result);
}

TEST_CASE("intersect", "[intersect]")
{
    Solution so;
    vector<int> nums1;
    vector<int> nums2;
    vector<int> output;
    nums1 = [1,2,2,1], nums2 = [2,2]
输出：[2,2]
}