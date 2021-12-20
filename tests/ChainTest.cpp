#include <catch2/catch_test_macros.hpp>
#include "../include/Chain.h"
#include <cmath>
#include <iostream>
#include <vector>
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

    SECTION("reversList")
    {
        auto getTestList = [](std::vector<int> vals){
            struct ListNode* head = nullptr;
            struct ListNode* prv = nullptr;
            for(const auto val : vals)
            {
                struct ListNode* list = new struct ListNode(val);
                if (!head)
                {
                    head = list;
                }
                if (prv)
                {
                    prv->next = list;
                }
                prv = list;

            }
            auto tmp = head;
            while(tmp)
            {
                std::cout << tmp->val << " ";
                tmp = tmp->next;
            }
            std::cout << std::endl;
            return head;
        };
        // struct ListNode* list1 = new struct ListNode;
        // auto num1 = so.listToNum(list1);
        // REQUIRE(num1 == 0);

        // struct ListNode* list2 = new struct ListNode(2);
        // struct ListNode* tmp1 = new struct ListNode(4);
        // struct ListNode* tmp2 = new struct ListNode(3);
        // tmp1->next = tmp2;
        // list2->next = tmp1;

        // struct ListNode* list3 = new struct ListNode(5);
        // struct ListNode* tmp3 = new struct ListNode(6);
        // struct ListNode* tmp4 = new struct ListNode(4);
        // tmp3->next = tmp4;
        // list3->next = tmp3;
        auto list1 = getTestList({0,8,6,5,6,8,3,5,7});
        auto list2 = getTestList({9,9,9,9});
//                auto list1 = getTestList({5});
//                auto list2 = getTestList({5});
        auto list = so.addTwoNumbers(list2, list1);
        while(list)
        {
            std::cout << list->val << " ";
            list = list->next;
        }
        // REQUIRE(num2 == 342);
    }
}
