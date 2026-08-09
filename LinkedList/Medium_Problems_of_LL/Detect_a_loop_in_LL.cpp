#include <bits/stdc++.h>
using namespace std;

// Node class represents a node in a linked list
class ListNode {
public:
    int data;
    ListNode* next;

    // Constructor with data and next node
    ListNode(int data1, ListNode* next1) {
        data = data1;
        next = next1;
    }

    // Constructor with only data
    ListNode(int data1) {
        data = data1;
        next = nullptr;
    }
};

// Hash map 
// TC =O(n) and Sc = O(n)
bool hasCycle(ListNode* head) {

if(head == nullptr || head->next == nullptr) {
    return false;
}
unordered_map<ListNode*, int> map;
ListNode* temp = head;
while(temp != nullptr) {
    // If node already exists, cycle is present
    if(map.find(temp) != map.end()) {
        return true;
    }
    map[temp] = 1;
    temp = temp->next;
}
return false;


}
// Floyd's Cycle Detection Algorithm
// Time  : O(n)
// Space : O(1)
bool hasCycle(ListNode* head) {

    // Empty list or only one node
    if(head == nullptr || head->next == nullptr) {
        return false;
    }

    ListNode* slow = head;
    ListNode* fast = head;

    while(fast != nullptr && fast->next != nullptr) {

        slow = slow->next;          // moves 1 step
        fast = fast->next->next;    // moves 2 steps

        // Both pointers meet
        if(slow == fast) {
            return true;
        }
    }

    return false;
}
