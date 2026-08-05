#include<bits/stdc++.h>
using namespace std;
// Delete a node in LL
// ✅ Delete Head
// ✅ Delete Tail
// ✅ Delete at Position
// ✅ Delete by Value

// self Node Structure
struct Node{
    int data;
    Node* next;

    Node(int data1){
        data = data1;
        next = nullptr;
    }

    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }
};

// Convert Array to Linked List
Node* Convert_to_Array_to_LL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;

    for(int i = 1; i < arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }

    return head;
}

// Delete Head
Node* Deleting_Head(Node* head){
    if(head == nullptr){
        return nullptr;
    }

    Node* temp = head;
    head = head->next;
    delete temp;

    return head; // modified array
}
// Delete Toil     
Node* Deleting_Last(Node* head){ // 2nd last elemnt to find out
    if(head == nullptr or head->next == nullptr){
        return nullptr;
    }
    Node* temp = head;
    while(temp->next->next != NULL){
        temp =temp->next;
    }
    delete temp->next;
    temp->next=nullptr; 

    return head; // modified array
}
// Delete K Position
Node* Deleting_K_position(Node* head, int k){ // 2nd last elemnt to find out
    if(head == nullptr){
        return nullptr;
    }
    if(k == 1){
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    Node*temp = head ;
    Node*Previous = nullptr;
    int cnt =1;
    while(temp != NULL){
        if(cnt == k){
            Previous->next = temp->next;
            delete temp; // position
            break;
        }
        Previous=temp;
        temp=  temp->next;
        cnt++;
    } 
    return head; // modified array
}

// Delete value
Node* Deleting_K_Values(Node* head, int val){ // 2nd last elemnt to find out
    if(head == nullptr){
        return nullptr;
    }
    if(head->data == val){
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    Node*temp = head ;
    Node*Previous = nullptr;

    while(temp != NULL){
        if(temp->data == val){
            Previous->next = temp->next;
            delete temp; // position
            break;
        }
        Previous=temp;
        temp =  temp->next;
    } 
    return head; // modified array
}


// Print Linked List
void printLL(Node* head){
    Node* temp = head;

    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main(){

    vector<int> arr = {1,2,3,4,5};

    // Convert array to linked list
    Node* head = Convert_to_Array_to_LL(arr);

    cout << "Before Deleting Head: ";
    printLL(head);

    // Delete head
    head = Deleting_Head(head);

    // Delete last or toil
    head = Deleting_Last(head); 

    // Delete K position
    head = Deleting_K_position(head,2); 

    // Delete Value
    head = Deleting_K_Values(head,2); 

    cout << "After Deleting Head: ";
    printLL(head);

    return 0;
}