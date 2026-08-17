#include <bits/stdc++.h>
using namespace std;

// Definition of special linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode *child;

    ListNode()
    {
        val = 0;
        next = NULL;
        child = NULL;
    }

    ListNode(int data1)
    {
        val = data1;
        next = NULL;
        child = NULL;
    }

    ListNode(int data1, ListNode *next1, ListNode* next2)
    {
        val = data1;
        next = next1;
        child = next2;
    }
};


class Solution {
public:

    // Merge two sorted linked lists
    ListNode* merge(ListNode* L1, ListNode* L2)
    {
        ListNode* dummy = new ListNode(-1);
        ListNode* res = dummy;

        while (L1 != nullptr && L2 != nullptr)
        {
            if (L1->val < L2->val)
            {
                res->child = L1;
                res = res->child;
                L1 = L1->child;
            }
            else
            {
                res->child = L2;
                res = res->child;
                L2 = L2->child;
            }

            res->next = nullptr;
        }

        // Attach remaining nodes
        if (L1 != nullptr)
        {
            res->child = L1;
        }
        else
        {
            res->child = L2;
        }

        return dummy->child;
    }

    // Flatten the linked list
    ListNode* flattenLinkedList(ListNode* &head)
    {
        // Base case
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }

        // Flatten remaining lists
        ListNode* merge_Head = flattenLinkedList(head->next);

        // Merge current list with flattened list
        return merge(head, merge_Head);
    }
};