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
    int expectResult{0};
    std::vector<int> input;
    std::vector<int> input2;
    std::vector<int> output;
    int index = 0;
    bool outputBool = false;

}; // class SolutionChainTestsFixture

TEST_CASE_METHOD(SolutionChainTestsFixture, "removeNthFromEnd", "[removeNthFromEnd]"
                                                                "[Solution_ChainTests]")
{
    SECTION("1")
    {
        input = {1, 2, 3, 4, 5};
        index = 2;
        output = {1, 2, 3, 5};
    }

    SECTION("2")
    {
        input = {1};
        index = 1;
        output = {};
    }
    SECTION("3")
    {
        input = {1, 2};
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
        input = {1, 2, 3, 4, 5};
        index = 5;
        output = {2, 3, 4, 5};
    }

    ListNode *head = so.createChain(input);
    auto result = so.removeNthFromEnd(head, index);
    REQUIRE(SolutionTestUtil::isSameVector(so.printChain(result), output));
}

TEST_CASE_METHOD(SolutionChainTestsFixture, "reverseList", "[reverseList]"
                                                           "[Solution_ChainTests]")
{
    SECTION("1")
    {
        input = {1, 2, 3, 4, 5};
        output = {5, 4, 3, 2, 1};
    }
    SECTION("2")
    {
        input = {1, 2};
        output = {2, 1};
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

TEST_CASE_METHOD(SolutionChainTestsFixture, "mergeTwoLists", "[mergeTwoLists]"
                                                             "[Solution_ChainTests]")
{
    SECTION("")
    {
        input = {1, 2, 4};
        input2 = {1, 3, 4};
        output = {1, 1, 2, 3, 4, 4};
    }
    SECTION("")
    {
        input = {};
        input2 = {};
        output = {};
    }
    SECTION("")
    {
        input = {};
        input2 = {0};
        output = {0};
    }
    SECTION("")
    {
        input = {};
        input2 = {0, 1, 2, 3};
        output = {0, 1, 2, 3};
    }
    SECTION("")
    {
        input = {0, 1, 2, 3};
        input2 = {};
        output = {0, 1, 2, 3};
    }
    SECTION("")
    {
        input = {0};
        input2 = {1, 2, 3};
        output = {0, 1, 2, 3};
    }
    SECTION("")
    {
        input2 = {0};
        input = {1, 2, 3};
        output = {0, 1, 2, 3};
    }
    SECTION("")
    {
        input = {1, 2, 3};
        input2 = {1, 2, 3};
        output = {1, 1, 2, 2, 3, 3};
    }
    auto list1 = so.createChain(input);
    auto list2 = so.createChain(input2);
    auto result = so.mergeTwoLists(list1, list2);
    REQUIRE(SolutionTestUtil::isSameVector(output, so.printChain(result)));
}

TEST_CASE_METHOD(SolutionChainTestsFixture, "isPalindrome", "[isPalindrome]"
                                                            "[Solution_ChainTests]")
{
    SECTION("")
    {
        input = {1, 2, 2, 1};
        outputBool = true;
    }
    SECTION("")
    {
        input = {1, 2, 3, 2, 1};
        outputBool = true;
    }
    SECTION("")
    {
        input = {1, 2};
        outputBool = false;
    }
    SECTION("")
    {
        input = {1};
        outputBool = true;
    }
    auto head = so.createChain(input);
    REQUIRE(so.isPalindrome(head) == outputBool);
}