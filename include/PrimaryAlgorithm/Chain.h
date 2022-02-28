/*
初级算法-链表
*/
#include <vector>
#include <iostream>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

    ListNode *createChain(vector<int> vals)
    {
        ListNode *head = nullptr;
        ListNode *cur = nullptr;
        for (const auto &val : vals)
        {
            auto node = new ListNode(val);
            if (!head)
            {
                head = node;
                cur = node;
            }
            else
            {
                cur->next = node;
                cur = cur->next;
            }
        }

        return head;
    }

    vector<int> printChain(ListNode *head)
    {
        vector<int> vals;
        while (head)
        {
            cout << head->val << " ";
            vals.push_back(head->val);
            head = head->next;
        }
        cout << endl;
        return vals;
    }
    /*
    删除链表中的节点
    请编写一个函数，用于 删除单链表中某个特定节点 。在设计函数时需要注意，你无法访问链表的头节点 head ，只能直接访问要被删除的节点 。
    题目数据保证需要删除的节点 不是末尾节点 。
    */
public:
    void deleteNode(ListNode *node)
    {
        if (!node->next)
        {
            return;
        }

        node->val = node->next->val;
        node->next = node->next->next;
    }
    /*
    删除链表的倒数第N个节点
    给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
    */
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (!head->next && n > 0)
        {
            return nullptr;
        }
        auto removeNode = head;
        auto endNode = head;
        for (int i = 0; i < n; ++i)
        {
            if (endNode)
            {
                endNode = endNode->next;
            }
            else
            {
                return nullptr;
            }
        }

        ListNode *preNode = nullptr;
        while (endNode)
        {
            if (!preNode)
            {
                preNode = removeNode;
            }
            else
            {
                preNode = preNode->next;
            }
            endNode = endNode->next;
            removeNode = removeNode->next;
        }

        if (removeNode == head)
        {
            head = head->next;
        }
        else if (preNode && removeNode && !removeNode->next)
        {
            preNode->next = nullptr;
        }
        else
        {
            preNode->next = removeNode->next;
        }

        return head;
    } // removeNthFromEnd
    /*
    反转链表
    给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。*/
public:
    ListNode *reverseList(ListNode *head)
    {
        if (!head)
        {
            return head;
        }
        auto begin = head;
        auto next = head->next;
        while (head && next)
        {
            auto nextNext = next->next;
            next->next = head;
            head = next;
            next = nextNext;
        }
        begin->next = nullptr;
        return head;
    } // reverseList

    /*
    合并两个有序链表
    将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的
    */
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (!list1 || !list2)
        {
            return list1 ? list1 : list2;
        }

        ListNode *list = nullptr;
        ListNode *insertList = nullptr;
        if (list1->val <= list2->val)
        {
            list = list1;
            insertList = list2;
        }
        else
        {
            list = list2;
            insertList = list1;
        }
        ListNode *head = list;

        ListNode *preNode = nullptr;
        while (insertList && list)
        {
            if (insertList->val < list->val)
            {
                preNode->next = insertList;
                auto tmp = insertList->next;
                insertList->next = list;
                preNode = insertList;
                insertList = tmp;
            }
            else
            {
                if (!preNode)
                {
                    preNode = list;
                }
                else
                {
                    preNode = preNode->next;
                }
                list = list->next;
            }
        }

        if (insertList && preNode)
        {
            preNode->next = insertList;
        }

        return head;
    } // mergeTwoLists

    /*
    回文链表
    给你一个单链表的头节点 head ，请你判断该链表是否为回文链表。如果是，返回 true ；否则，返回 false 。
    */
public:
    bool isPalindrome(ListNode *head)
    {
        bool result = true;
        auto fast = head;
        auto mid = head;
        while (fast && fast->next)
        {
            fast = fast->next->next;
            mid = mid->next;
        }
        auto begin = mid;
        if (begin)
        {
            auto next = begin->next;
            while (begin && next)
            {
                auto nextNext = next->next;
                next->next = begin;
                begin = next;
                next = nextNext;
            }
            mid->next = nullptr;
        }

        while (begin && head)
        {
            if (begin->val != head->val)
            {
                result = false;
                break;
            }
            else
            {
                begin = begin->next;
                head = head->next;
            }
        }

        return result;

    } // isPalindrome

    /*
    环形链表
    给你一个链表的头节点 head ，判断链表中是否有环。
    如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。如果 pos 是 -1，则在该链表中没有环。注意：pos 不作为参数进行传递，仅仅是为了标识链表的实际情况。
    如果链表中存在环，则返回 true 。 否则，返回 false 。
    */
public:
    bool hasCycle(ListNode *head)
    {
        while (head)
        {
            if (head->val != INT_MAX)
            {
                head->val = INT_MAX;
                head = head->next;
            }
            else
            {
                return true;
            }
        }
        return false;
    } // hasCycle

    ListNode* swapPairs(ListNode* head) {
        if (!head)
        {
            return head;
        }

        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        ListNode* node1 = head;
        ListNode* node2 = head->next;
        while(node1 && node2)
        {
            next = node2->next;
            node2->next = node1;
            if (prev)
            {
                prev->next = node2;
            }
            else
            {
                head = node2;
            }

            node1->next = next;
            prev = node1;

            node1 = node1->next;
            if (node1)
            {
                node2 = node1->next;
            }
            else
            {
                node2 = nullptr;
            }
        }

        return head;
    }
};
