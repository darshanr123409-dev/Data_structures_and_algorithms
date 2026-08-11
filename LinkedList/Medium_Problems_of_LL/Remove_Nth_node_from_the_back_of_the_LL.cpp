#include <bits/stdc++.h>
using namespace std;

// ============================================================
// Definition for singly-linked list
// ============================================================

struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode* next)
        : val(x), next(next) {}
};


// ============================================================
// Solution
// ============================================================

class Solution {
public:

    ListNode* removeNthFromEnd(ListNode* head, int n) {

        // Dummy node
        ListNode* dummy = new ListNode(0);

        dummy->next = head;

        // Two pointers
        ListNode* fast = dummy;
        ListNode* slow = dummy;


        // Move fast n + 1 steps
        for (int i = 0; i <= n; i++) {

            fast = fast->next;
        }


        // Move both pointers
        while (fast != nullptr) {

            fast = fast->next;

            slow = slow->next;
        }


        // Node to delete
        ListNode* deleteNode = slow->next;


        // Remove node
        slow->next = slow->next->next;


        // Free memory
        delete deleteNode;


        // New head
        ListNode* newHead = dummy->next;


        // Delete dummy
        delete dummy;


        return newHead;
    }
};


// ============================================================
// Print Linked List
// ============================================================

void printList(ListNode* head) {

    ListNode* temp = head;

    while (temp != nullptr) {

        cout << temp->val;

        if (temp->next != nullptr) {
            cout << " -> ";
        }

        temp = temp->next;
    }

    cout << endl;
}
