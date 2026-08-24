#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode *prev;

    ListNode()
    {
        val = 0;
        next = NULL;
        prev = NULL;
    }

    ListNode(int data1)
    {
        val = data1;
        next = NULL;
        prev = NULL;
    }

    ListNode(int data1, ListNode *next1, ListNode *prev1)
    {
        val = data1;
        next = next1;
        prev = prev1;
    }
};

class Solution {
public:
    ListNode* removeDuplicates(ListNode* head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }

        ListNode* temp = head;

        while (temp != nullptr && temp->next != nullptr)
        {
            ListNode* newNode = temp->next;

            if (newNode->val == temp->val)
            {
                ListNode* Dupli = newNode;

                newNode = newNode->next;

                temp->next = newNode;

                if (newNode != nullptr)
                {
                    newNode->prev = temp;
                }

                delete Dupli;
            }
            else
            {
                temp = temp->next;
            }
        }

        return head;
    }
};

