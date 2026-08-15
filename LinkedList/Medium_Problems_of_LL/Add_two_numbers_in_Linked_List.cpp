#include <bits/stdc++.h>
using namespace std;

// Definition of singly linked list
struct ListNode {
    int val;
    ListNode* next;

    ListNode() {
        val = 0;
        next = nullptr;
    }

    ListNode(int x) {
        val = x;
        next = nullptr;
    }

    ListNode(int x, ListNode* next) {
        val = x;
        next = next;
    }
};

class Solution {
public:

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        // Dummy node
        ListNode* dummy = new ListNode(0);

        // temp points to the last node
        ListNode* temp = dummy;

        int carry = 0;

        // Continue while either list has nodes or carry exists
        while (l1 != nullptr || l2 != nullptr || carry) {

            int sum = 0;

            // Add value from l1
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }

            // Add value from l2
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }

            // Add carry
            sum += carry;

            // Calculate carry
            carry = sum / 10;

            // Create new node with digit
            ListNode* node = new ListNode(sum % 10);

            // Attach node
            temp->next = node;

            // Move temp
            temp = temp->next;
        }

        // Return actual head
        return dummy->next;
    }
};


// Insert node at end
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


// Print linked list
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


int main() {

    // Number 342
    // Stored as 2 -> 4 -> 3
    ListNode* l1 = nullptr;

    insertAtEnd(l1, 2);
    insertAtEnd(l1, 4);
    insertAtEnd(l1, 3);


    // Number 465
    // Stored as 5 -> 6 -> 4
    ListNode* l2 = nullptr;

    insertAtEnd(l2, 5);
    insertAtEnd(l2, 6);
    insertAtEnd(l2, 4);


    cout << "L1: ";
    printList(l1);

    cout << "L2: ";
    printList(l2);


    Solution obj;

    ListNode* result = obj.addTwoNumbers(l1, l2);


    cout << "Result: ";
    printList(result);


    return 0;
}