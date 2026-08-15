#include <bits/stdc++.h>
using namespace std;

// Definition of singly linked list
struct ListNode {
    int val;
    ListNode* next;

    ListNode() {
        val = 0;
        next = NULL;
    }

    ListNode(int data1) {
        val = data1;
        next = NULL;
    }

    ListNode(int data1, ListNode* next1) {
        val = data1;
        next = next1;
    }
};

class Solution {
public:

    // =========================================================
    // Approach 1: Iterative using Reverse
    // =========================================================

    ListNode* reverseList(ListNode* head) {

        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {

            ListNode* nextNode = curr->next;

            curr->next = prev;

            prev = curr;
            curr = nextNode;
        }

        return prev;
    }

    ListNode* addOneUsingReverse(ListNode* head) {

        // Step 1: Reverse the list
        head = reverseList(head);

        // Step 2: Add 1
        ListNode* temp = head;
        int carry = 1;

        while (temp != nullptr && carry) {

            temp->val += carry;

            if (temp->val == 10) {
                temp->val = 0;
                carry = 1;
            }
            else {
                carry = 0;
            }

            temp = temp->next;
        }

        // Step 3: Reverse back
        head = reverseList(head);

        // Step 4: If carry remains
        if (carry == 1) {

            ListNode* newHead = new ListNode(1);

            newHead->next = head;

            head = newHead;
        }

        return head;
    }


    // =========================================================
    // Approach 2: Iterative without Reverse
    // =========================================================

    ListNode* addOneWithoutReverse(ListNode* head) {

        ListNode* temp = head;

        // Store the last node which is not 9
        ListNode* lastNotNine = nullptr;

        while (temp != nullptr) {

            if (temp->val != 9) {
                lastNotNine = temp;
            }

            temp = temp->next;
        }

        // Case: All nodes are 9
        if (lastNotNine == nullptr) {

            ListNode* newHead = new ListNode(1);

            newHead->next = head;

            temp = head;

            while (temp != nullptr) {
                temp->val = 0;
                temp = temp->next;
            }

            return newHead;
        }

        // Increase the last non-9 digit
        lastNotNine->val++;

        // Set all digits after it to 0
        temp = lastNotNine->next;

        while (temp != nullptr) {

            temp->val = 0;

            temp = temp->next;
        }

        return head;
    }
};


// =========================================================
// Helper Functions
// =========================================================

void insertAtEnd(ListNode*& head, int value) {

    ListNode* newNode = new ListNode(value);

    if (head == nullptr) {
        head = newNode;
        return;
    }

    ListNode* temp = head;

    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = newNode;
}


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


// =========================================================
// Main
// =========================================================

int main() {

    ListNode* head = nullptr;

    // 129 + 1 = 130
    insertAtEnd(head, 1);
    insertAtEnd(head, 2);
    insertAtEnd(head, 9);

    cout << "Original: ";
    printList(head);

    Solution obj;

    // Approach 1
    ListNode* result1 = obj.addOneUsingReverse(head);

    cout << "Using Reverse: ";
    printList(result1);


    // Create another list for Approach 2
    ListNode* head2 = nullptr;

    insertAtEnd(head2, 1);
    insertAtEnd(head2, 2);
    insertAtEnd(head2, 9);

    // Approach 2
    ListNode* result2 = obj.addOneWithoutReverse(head2);

    cout << "Without Reverse: ";
    printList(result2);

    return 0;
}