#include <catch2/catch_test_macros.hpp>
#include "../include/Solution_Chain.h"
#include "SolutionTestUtil.h"

using ListNode = Solution::ListNode;

class SolutionChainTestsFixture
{
public:
    SolutionChainTestsFixture()
    {
        so = Solution();
    }
    Solution so;
    int expectResult{ 0 };
    std::vector<int> input;
    std::vector<int> output;
    int index = 0;


}; // class SolutionChainTestsFixture

TEST_CASE_METHOD(SolutionChainTestsFixture, "removeNthFromEnd", "[removeNthFromEnd]""[Solution_ChainTests]")
{
    SECTION("1")
    {
        input = {1,2,3,4,5};
        index = 2;
        output = {1,2,3,5};
    }

    SECTION("2")
    {
        input = {1};
        index = 1;
        output = {};
    }
    SECTION("3")
    {
        input = {1,2};
        index = 1;
        output = {1};
    }
    SECTION("4")
    {
        input = {1};
        index = 1;
        output = {};
    }
    SECTION("5")
    {
        input = {1,2,3,4,5};
        index = 5;
        output = {2,3,4,5};
    }

    ListNode* head = so.createChain(input);
    auto result = so.removeNthFromEnd(head, index);
    REQUIRE(SolutionTestUtil::isSameVector(so.printChain(result), output));
}

TEST_CASE_METHOD(SolutionChainTestsFixture, "reverseList", "[reverseList]""[Solution_ChainTests]")
{
    SECTION("1")
    {
        input = {1,2,3,4,5};
        output = {5,4,3,2,1};
    }
    SECTION("2")
    {
        input = {1,2};
        output = {2,1};
    }
    SECTION("3")
    {
        input = {};
        output = {};
    }
    SECTION("4")
    {
        input = {1};
        output = {1};
    }
    auto head = so.createChain(input);
    auto result = so.reverseList(head);
    REQUIRE(SolutionTestUtil::isSameVector(output, so.printChain(result)));
}