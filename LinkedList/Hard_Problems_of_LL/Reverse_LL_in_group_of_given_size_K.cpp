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
    ListNode* reverseKGroup(ListNode* head, int k) {

        // Check if there are at least k nodes
        ListNode* temp = head;

        for (int i = 0; i < k; i++) {
            if (temp == nullptr) {
                return head;
            }
            temp = temp->next;
        }

        // Reverse k nodes
        ListNode* prev = nullptr;
        ListNode* curr = head;

        for (int i = 0; i < k; i++) {
            ListNode* nextNode = curr->next;

            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        // Connect current group with remaining groups
        head->next = reverseKGroup(curr, k);

        // prev is the new head of this group
        return prev;
    }
};

// Function to print linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {

    // Create linked list:
    // 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int k = 2;

    Solution obj;

    ListNode* newHead = obj.reverseKGroup(head, k);

    // Output:
    // 2 1 4 3 5
    printList(newHead);

    return 0;
} 