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
        if (!l1->next && l1->val == 0)
        {
            return (l2);
        }

        if (!l2->next && l2->val == 0)
        {
            return (l1);
        }

        bool plusOne = false;
        auto tail1 = l1;
        auto head1 = l1;
        while(l1 && l2)
        {
            tail1 = l1;
            if (plusOne)
            {
                l1->val += 1;
            }
            plusOne = false;
 
            l1->val += l2->val;
            if (l1->val > 9)
            {
                plusOne = true;
                l1->val -= 10;
            }

            l1 = l1->next;
            l2 = l2->next;
        }

        if (!l1 && l2)
        {
            tail1->next = l2;
            while (plusOne && l2)
            {
                tail1 = l2;
                l2->val += 1;
                plusOne = false;
                if (l2->val > 9)
                {
                    plusOne = true;
                    l2->val -= 10;
                    l2 = l2->next;
                }
            }
        }

        if (l1 && !l2)
        {
            while (plusOne && l1)
            {
                tail1 = l1;
                l1->val += 1;
                plusOne = false;
                if (l1->val > 9)
                {
                    plusOne = true;
                    l1->val -= 10;
                    l1 = l1->next;
                }
            }
        }
        if(plusOne)
        {
            struct ListNode* tmp = new struct ListNode(1);
            tail1->next = tmp;
        }
        return head1;
    }
 
    ListNode* reversList(ListNode* list)
    {
        ListNode* head = list;
        auto cur = head;
        ListNode* prv = nullptr;
        while(cur)
        {
            auto tmp = cur->next;
            cur->next = prv;
            prv = cur;
            cur = tmp;
        }
        return prv;
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
