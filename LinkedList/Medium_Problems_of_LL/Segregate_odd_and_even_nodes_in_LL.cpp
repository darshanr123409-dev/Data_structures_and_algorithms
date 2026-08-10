#include <bits/stdc++.h>
using namespace std;

// Node structure
struct ListNode {
    int val;
    ListNode* next;

    // Constructor
    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

// Odd Even Linked List
ListNode* oddEvenList(ListNode* head) {

    // Empty list or one node
    if(head == nullptr || head->next == nullptr)
        return head;

    // Odd position pointer
    ListNode* odd = head;

    // Even position pointer
    ListNode* even = head->next;

    // Save the first even node
    ListNode* evenHead = head->next;

    while(even != nullptr && even->next != nullptr) {

        // Connect odd nodes
        odd->next = odd->next->next;

        // Connect even nodes
        even->next = even->next->next;

        // Move pointers
        odd = odd->next;
        even = even->next;
    }

    // Connect odd list with even list
    odd->next = evenHead;

    return head;
}

