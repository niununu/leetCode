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
//     std::vector<int> input;
//     std::vector<int> input2;
//     std::vector<int> output;
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
