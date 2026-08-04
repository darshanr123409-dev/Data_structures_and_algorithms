#include<bits/stdc++.h>
using namespace std;
// Insert a node in LL
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



// Insert a Head
Node* Inserting_Head(int val,Node*head){
    Node* temp = new Node(val,head);
    return temp;
}

// Insert a last or toil
Node* Inserting_Last(Node* head,int val){ //  last elemnt to find out
    if(head == nullptr ){
        return nullptr;
    }
    Node* temp = head;
    while(temp->next!= NULL){
        temp =temp->next;
    }
    Node* NewNode = new Node(val);
    temp->next = NewNode;
    return head; // modified array
}
// Insert in Kth position
Node* Inserting_Kth_position(Node* head,int k,int el){ //  K behind  elemnt to find out
    if(head == nullptr ){ // if  1
        if(k==1) return new Node(el);
        else    return nullptr;
    }
    if(k == 1){
        return new Node(el,head);
    }
    Node* temp = head;
    int cnt=1; 
    while( temp != nullptr){
        if(cnt==k-1) // behind temp
        {
            Node* x = new Node(el);
            x->next = temp->next;
            temp->next = x;
            break; 
        }
        temp = temp->next;
        cnt++;
    }
    return head; // modified array
}

// Insert in element before the values
Node* Insert_Before_value(Node* head,int val,int el){ //  value find out next insert
    if(head == nullptr ){ 
         return nullptr;
    }
    if(head->data == val){ // head is equal to value
        return new Node(el,head);
    }
    Node* temp = head;
    bool found = false; // in case not found
    while( temp->next != nullptr){
        if(temp->next->data == val) // before temp 
        {
            Node* x = new Node(el);
            x->next = temp->next;
            temp->next = x;
            found=1;
            break; 
        }
        temp = temp->next;
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

    cout << "Before Inserting Head: ";
    printLL(head);

    //Insert to head
    head = Inserting_Head(100,head); // in first node 

    //Insert to Last
    head = Inserting_Last(head,120); // in last node 

    //Insert to Last
    head = Inserting_Kth_position(head,4,100);

    // Insert in element before the values
    head = Insert_Before_value(head,4,6);

    cout << "After Inserting Head: "; 
    printLL(head);

    return 0;
}