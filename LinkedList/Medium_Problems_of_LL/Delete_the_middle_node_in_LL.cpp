#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:

    ListNode* deleteMiddle(ListNode* head) {

        // If list is empty or has only one node
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }

        // Slow and fast pointers
        ListNode* slow = head;
        ListNode* fast = head;

        // Node before middle
        ListNode* prev = nullptr;

        // Find middle node
        while (fast != nullptr && fast->next != nullptr) {

            prev = slow;

            slow = slow->next;

            fast = fast->next->next;
        }

        // Delete middle node
        prev->next = slow->next;

        return head;
    }
};


