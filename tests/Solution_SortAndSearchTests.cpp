#include <catch2/catch_test_macros.hpp>
#include "../include/Solution_SortAndSearch.h"
#include "SolutionTestUtil.h"

class SolutionSortAndSearchTestsFixture
{
public:
    SolutionSortAndSearchTestsFixture()
    {
        so = Solution();
    }
    Solution so;
    std::vector<int> input;
    std::vector<int> input2;
    std::vector<int> output;
}; // class SolutionSortAndSearchTestsFixture

TEST_CASE_METHOD(SolutionSortAndSearchTestsFixture, "merge", "[merge]""[Solution_SortAndSearchTests]")
{
    int m = 3, n = 3;
    SECTION("")
    {
        input = {1,2,3,0,0,0};
        input2 = {2,5,6};
        output = {1,2,2,3,5,6};
        m = 3, n = 3;
    }
    SECTION("")
    {
        input = {1};
        input2 = {};
        output = {1};
        m = 1, n = 0;
    }
    SECTION("")
    {
        input = {0};
        input2 = {1};
        output = {1};
        m = 0, n = 1;
    }
    SECTION("")
    {
        input = {5,6,7,0};
        input2 = {1};
        output = {1,5,6,7};
        m = 3, n = 1;
    }
    SECTION("")
    {
        input = {5,6,7,0,0,0};
        input2 = {1,2,3};
        output = {1,2,3,5,6,7};
        m = 3, n = 3;
    }
    so.merge(input, m, input2, n);
    REQUIRE(SolutionTestUtil::isSameVector(input, output));
}

TEST_CASE_METHOD(SolutionSortAndSearchTestsFixture, "firstBadVersion", "[firstBadVersion]""[Solution_SortAndSearchTests]")
{
    so.expectVersion = 4;
    int inputInt = 5;
    SECTION("")
    {
        inputInt = 5;
        so.expectVersion = 4;
    }
    SECTION("")
    {
        inputInt = 1;
        so.expectVersion = 1;
    }
    SECTION("")
    {
        inputInt = 6;
        so.expectVersion = 3;
    }
    SECTION("")
    {
        inputInt = 6;
        so.expectVersion = 1;
    }
    SECTION("")
    {
        inputInt = 6;
        so.expectVersion = 6;
    }
    SECTION("")
    {
        inputInt = 7;
        so.expectVersion = 7;
    }
    SECTION("")
    {
        inputInt = 7;
        so.expectVersion = 6;
    }
    SECTION("")
    {
        inputInt = 7;
        so.expectVersion = 1;
    }
    REQUIRE(so.firstBadVersion(inputInt) == so.expectVersion);
}