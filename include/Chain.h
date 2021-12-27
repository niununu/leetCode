// *
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
 
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto num1 = listToNum(l1);
        auto num2 = listToNum(l2);
    }

    double pow(int x, int y)
    {
        double result = 1;
        for (int i = 1; i <= y; ++i)
        {
            result = x * result;
        }
        return result;
    }

    double listToNum(ListNode* list)
    {
        double result = 0;
        int len = 0;
        ListNode* tail = list;
        while(list)
        {
            tail = list;
            result = result + list->val * pow(10, len);
            list = list->next;
            ++len;
        }

        if (tail->val == 0)
        {
            result = 0;
        }

        return result;
    }
};