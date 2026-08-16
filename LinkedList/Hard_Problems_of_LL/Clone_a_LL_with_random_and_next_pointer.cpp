#include <bits/stdc++.h>
using namespace std;

// Definition for a Node
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
public:

    // Step 1: Insert copied nodes between original nodes
    void Insert_copy_between(Node* head) {

        Node* temp = head;

        while (temp != nullptr) {

            Node* CopyNode = new Node(temp->val);

            CopyNode->next = temp->next;
            temp->next = CopyNode;

            temp = temp->next->next;
        }
    }

    // Step 2: Connect random pointers of copied nodes
    void Cennect_random_pointer(Node* head) {

        Node* temp = head;

        while (temp != nullptr) {

            Node* CopyNode = temp->next;

            if (temp->random != nullptr)
                CopyNode->random = temp->random->next;
            else
                CopyNode->random = nullptr;

            temp = temp->next->next;
        }
    }

    // Step 3: Separate original list and copied list
    Node* get_the_copy_List(Node* head) {

        Node* temp = head;

        Node* dummy = new Node(-1);
        Node* res = dummy;

        while (temp != nullptr) {

            // Copy node
            res->next = temp->next;
            res = res->next;

            // Restore original list
            temp->next = temp->next->next;
            temp = temp->next;
        }

        return dummy->next;
    }

    Node* copyRandomList(Node* head) {

        if (head == nullptr)
            return nullptr;

        // Step 1
        Insert_copy_between(head);

        // Step 2
        Cennect_random_pointer(head);

        // Step 3
        return get_the_copy_List(head);
    }
};


// Function to print the list
void printList(Node* head) {

    while (head != nullptr) {

        cout << "Node Value: " << head->val;

        if (head->random != nullptr)
            cout << ", Random: " << head->random->val;
        else
            cout << ", Random: NULL";

        cout << endl;

        head = head->next;
    }
}


int main() {

    /*
        Create the following list:

        Node 1 -> Node 2 -> Node 3 -> Node 4 -> Node 5

        Random pointers:

        1 -> 3
        2 -> 1
        3 -> 5
        4 -> 3
        5 -> 2
    */

    Node* head = new Node(1);

    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);


    // Set random pointers

    head->random = head->next->next;                    // 1 -> 3

    head->next->random = head;                          // 2 -> 1

    head->next->next->random =
        head->next->next->next->next;                   // 3 -> 5

    head->next->next->next->random =
        head->next->next;                               // 4 -> 3

    head->next->next->next->next->random =
        head->next;                                     // 5 -> 2


    cout << "Original List:" << endl;

    printList(head);


    Solution obj;

    // Create deep copy
    Node* copyHead = obj.copyRandomList(head);


    cout << "\nCopied List:" << endl;

    printList(copyHead);


    return 0;
} 
