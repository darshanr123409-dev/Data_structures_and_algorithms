#include <bits/stdc++.h>
using namespace std;

// Doubly Linked List Node
struct Node {
    int data;
    Node* next;
    Node* back;

    // Constructor
    Node(int data1, Node* next1, Node* back1) {
        data = data1;
        next = next1;
        back = back1;
    }

    // Constructor
    Node(int data1) {
        data = data1;
        next = nullptr;
        back = nullptr;
    }

    // Convert Array to DLL
    static Node* Convert_to_Array_to_DLL(vector<int> arr) {

        if(arr.empty())
            return nullptr;

        Node* head = new Node(arr[0]);
        Node* previ = head;

        for(int i = 1; i < arr.size(); i++) {

            Node* temp = new Node(arr[i], nullptr, previ);

            previ->next = temp;
            previ = temp;
        }

        return head;
    }
};
//Logic
// temp = a
// a = b
// b = temp

// Reverse Doubly Linked List
Node* Reverse_DLL(Node* head) {

    if(head == nullptr || head->next == nullptr)
        return head;

    Node* current = head;
    Node* last = nullptr;

    while(current != nullptr) {

        // Swap next and back
        last = current->back;

        current->back = current->next;
        current->next = last;

        // Move to next node
        current = current->back;
    }

    // New head
    return last->back;
}


// Print DLL
void print(Node* head) {

    while(head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }

    cout << endl;
}


int main() {

    vector<int> arr = {1, 2, 3, 4, 5};

    // Convert array to DLL
    Node* head = Node::Convert_to_Array_to_DLL(arr);

    cout << "Before Reversing DLL : ";
    print(head);

    // Reverse DLL
    head = Reverse_DLL(head);

    cout << "After Reversing DLL  : ";
    print(head);

    return 0;
}
```
