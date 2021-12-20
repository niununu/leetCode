#include <catch2/catch_test_macros.hpp>
#include "../include/Chain.h"
#include <cmath>

TEST_CASE("Solution", "[ChainTest]")
{
    Solution so;
    SECTION("pow")
    {
        REQUIRE(so.pow(10,0) == pow(10,0));
        REQUIRE(so.pow(10,1) == pow(10,1));
        REQUIRE(so.pow(10,2) == pow(10,2));
        REQUIRE(so.pow(10,10) == pow(10,10));
    }

    SECTION("convertToNum")
    {
        struct ListNode* list1 = new struct ListNode;
        auto num1 = so.listToNum(list1);
        REQUIRE(num1 == 0);

        struct ListNode* list2 = new struct ListNode;
        list2->val = (2);
        struct ListNode* tmp1 = new struct ListNode;
        tmp1->val = (4);
        struct ListNode* tmp2 = new struct ListNode;
        tmp2->val = (3);
        tmp1->next = tmp2;
        list2->next = tmp1;

        auto num2 = so.listToNum(list2);
        REQUIRE(num2 == 342);
    }
}