#include<bits/stdc++.h>
using namespace std;

struct Node { // self define data types
    int data;
    Node* next;

    Node(int data1, Node* next1){  // Constructer
        data = data1;
        next = next1;
    }
    Node(int data1){  // Constructer
        data = data1;
        next = nullptr;
    }
    static Node* Convert_to_Array_to_LL(vector<int> arr){
        Node* head = new Node(arr[0]); // Always is First node is head
        Node* Mover = head;
        
        for(int i =1 ; i< arr.size() ;i++){
            Node* temp = new Node(arr[i]);
            Mover->next = temp;
            Mover = temp;
        }
        return head;
    }
};

// Optimal :- Tc = O(n) and Sc = O(1)
// Reverse  Linked List
Node* reverseList(Node* head) {

        Node* prev = nullptr;
        Node* temp = head;

        while (temp != nullptr) {

            Node* front = temp->next;

            temp->next = prev;

            prev = temp;

            temp = front;
        }

        return prev;
}

// Recursion :- Tc = O(n) and Sc = O(1)
// Recursive function to reverse the linked list
    Node* reverseList(Node* head) {
        // Base case: if list is empty or has one node
        if (head == NULL || head->next == NULL)
            return head;

        // Recursively reverse the rest of the list
        Node* newHead = reverseList(head->next);

        // Store the next node
        Node* front = head->next;

        // Make the next node point back to current
        front->next = head;

        // Break the current node's forward link
        head->next = NULL;

        // Return the new head of the reversed list
        return newHead;
}



