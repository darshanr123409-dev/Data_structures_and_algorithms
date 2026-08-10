#include <bits/stdc++.h>
using namespace std;

// Node definition
struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};


// Detect the starting node of the cycle
ListNode* detectCycle_2(ListNode* head) {

    // No cycle possible
    if(head == nullptr || head->next == nullptr) {
        return nullptr;
    }

    ListNode* slow = head;
    ListNode* fast = head;

    // Phase 1: Detect cycle
    while(fast != nullptr && fast->next != nullptr) {

        slow = slow->next;          // Move 1 step
        fast = fast->next->next;    // Move 2 steps

        // Cycle detected
        if(slow == fast) {

            // Phase 2: Find starting point of cycle
            slow = head;

            while(slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }

            // Both meet at cycle starting node
            return slow;
        }
    }

    // No cycle
    return nullptr;
}

