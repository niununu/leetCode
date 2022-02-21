#include <catch2/catch_test_macros.hpp>
#include "../TestUtils.h"
#include "../include/PrimaryAlgorithm/DynamicProgramming.h"
class DynamicProgrammingTestsFixture
{
public:
    DynamicProgrammingTestsFixture()
    {
        so = Solution();
    }
    Solution so;
    std::vector<int> input;
    std::vector<int> input2;
    std::vector<int> output;
}; // class DynamicProgrammingTestsFixture

TEST_CASE_METHOD(DynamicProgrammingTestsFixture, "lengthOfLIS", "[lengthOfLIS]""[DynamicProgrammingTests]""[testlab]")
{
    input = {0};
    // input = {10,9,2,5,3,7,101,18};
    auto result = so.lengthOfLIS(input);
    REQUIRE(result == 1);
}

TEST_CASE_METHOD(DynamicProgrammingTestsFixture, "findNumberOfLIS", "[findNumberOfLIS]""[DynamicProgrammingTests]""[testlab]")
{
    input = {2,2,2,2,2};
    // input = {10,9,2,5,3,7,101,18};
    auto result = so.findNumberOfLIS(input);
    REQUIRE(result == 5);
}

TEST_CASE_METHOD(DynamicProgrammingTestsFixture, "maxEnvelopes", "[maxEnvelopes]""[DynamicProgrammingTests]""[testlab]")
{
    vector<vector<int>> envelopes = {{5,4}, {6,4}, {6,7}, {2,3}};
    // input = {10,9,2,5,3,7,101,18};
    auto result = so.maxEnvelopes(envelopes);
    // REQUIRE(result == 5);
}
