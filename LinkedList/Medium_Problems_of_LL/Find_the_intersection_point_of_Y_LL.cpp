#include <bits/stdc++.h>
using namespace std;

// Definition of singly linked list
struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

class Solution {
public:

    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {

        if (headA == NULL || headB == NULL) {
            return NULL;
        }

        ListNode* pA = headA;
        ListNode* pB = headB;

        while (pA != pB) {

            if (pA == NULL) {
                pA = headB;
            }
            else {
                pA = pA->next;
            }

            if (pB == NULL) {
                pB = headA;
            }
            else {
                pB = pB->next;
            }
        }

        return pA;
    }
};


// Print linked list
void printList(ListNode* head) {

    ListNode* temp = head;

    while (temp != NULL) {

        cout << temp->val;

        if (temp->next != NULL) {
            cout << " -> ";
        }

        temp = temp->next;
    }

    cout << endl;
}


int main() {

    /*
              A: 4 → 1 ↘
                        8 → 4 → 5
              B: 5 → 6 → 1 ↗
    */

    // Common part
    ListNode* common1 = new ListNode(8);
    ListNode* common2 = new ListNode(4);
    ListNode* common3 = new ListNode(5);

    common1->next = common2;
    common2->next = common3;


    // List A
    ListNode* headA = new ListNode(4);
    ListNode* a2 = new ListNode(1);

    headA->next = a2;
    a2->next = common1;


    // List B
    ListNode* headB = new ListNode(5);
    ListNode* b2 = new ListNode(6);
    ListNode* b3 = new ListNode(1);

    headB->next = b2;
    b2->next = b3;
    b3->next = common1;


    cout << "List A: ";
    printList(headA);

    cout << "List B: ";
    printList(headB);


    // Find intersection
    Solution obj;

    ListNode* intersection = obj.getIntersectionNode(headA, headB);


    if (intersection != NULL) {
        cout << "Intersection Node: "
             << intersection->val << endl;
    }
    else {
        cout << "No Intersection" << endl;
    }


    return 0;
}