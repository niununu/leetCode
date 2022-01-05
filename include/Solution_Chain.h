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

    ListNode* createChain(vector<int> vals)
    {
        ListNode* head = nullptr;
        ListNode* cur = nullptr;
        for (const auto& val : vals)
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

    vector<int> printChain(ListNode* head)
    {
        vector<int> vals;
        while(head)
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
        if(!node->next)
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
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

        ListNode* preNode = nullptr;
        while(endNode)
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
        else if(preNode && removeNode && !removeNode->next)
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
    ListNode* reverseList(ListNode* head) {
        if (!head)
        {
            return head;
        }
        auto begin = head;
        auto next = head->next;
        while(head && next)
        {
            auto nextNext = next->next;
            next->next = head;
            head = next;
            next = nextNext;
        }
        begin->next = nullptr;
        return head;
    } // reverseList
};