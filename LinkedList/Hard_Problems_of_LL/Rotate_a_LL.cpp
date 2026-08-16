#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:

    // Find the kth node
    ListNode* findNthNode(ListNode* temp, int k) {

        int cnt = 1;

        while (temp != nullptr) {

            if (k == cnt)
                return temp;

            cnt++;
            temp = temp->next;
        }

        return temp;
    }

    ListNode* rotateRight(ListNode* head, int k) {

        // Empty list or no rotation
        if (head == nullptr || k == 0)
            return head;

        // Find length and last node
        ListNode* toil = head;
        int length = 1;

        while (toil->next != nullptr) {
            toil = toil->next;
            length++;
        }

        // If k is multiple of length
        if (k % length == 0)
            return head;

        // Reduce unnecessary rotations
        k = k % length;

        // Make circular linked list
        toil->next = head;

        // Find node before new head
        ListNode* newNode = findNthNode(head, length - k);

        // New head
        head = newNode->next;

        // Break the circular connection
        newNode->next = nullptr;

        return head;
    }
};

// Function to print linked list
void printList(ListNode* head) {

    while (head != nullptr) {
        cout << head->val;

        if (head->next != nullptr)
            cout << " -> ";

        head = head->next;
    }

    cout << endl;
}

int main() {

    // Create linked list
    // 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int k = 2;

    Solution obj;

    // Rotate the linked list
    head = obj.rotateRight(head, k);

    // Print result
    // 4 -> 5 -> 1 -> 2 -> 3
    printList(head);

    return 0;
}
