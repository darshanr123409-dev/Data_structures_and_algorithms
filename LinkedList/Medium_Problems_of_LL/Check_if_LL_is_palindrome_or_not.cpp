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


class Solution {
public:

    // Reverse a linked list
    ListNode* reverse(ListNode* head) {

        ListNode* prev = nullptr;
        ListNode* curr = head;

        while(curr) {

            ListNode* nextNode = curr->next;

            curr->next = prev;

            prev = curr;
            curr = nextNode;
        }

        return prev;
    }


    bool isPalindrome(ListNode* head) {

        // Empty list or one node
        if(head == nullptr || head->next == nullptr)
            return true;


        // Find the middle
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next && fast->next->next) {

            slow = slow->next;
            fast = fast->next->next;
        }


        // Reverse second half
        ListNode* secondHalf = reverse(slow->next);


        // Compare first half and reversed second half
        ListNode* firstHalf = head;
        ListNode* temp = secondHalf;

        while(temp) {

            if(firstHalf->val != temp->val)
                return false;

            firstHalf = firstHalf->next;
            temp = temp->next;
        }

        return true;
    }
};