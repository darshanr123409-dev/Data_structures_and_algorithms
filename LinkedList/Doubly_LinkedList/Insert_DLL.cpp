#include<bits/stdc++.h>
using namespace std;

// Insert a node in DLL (before) All
// ✅ Insert Head
// ✅ Insert Tail
// ✅ Insert at Position
// ✅ Insert Node

struct Node { // self define data types
    int data;
    Node* next;
    Node* back;

    Node(int data1, Node* next1,Node* back1){  // Constructer
        data = data1;
        next = next1;
        back = back1; 
    }
    Node(int data1){  // Constructer
        data = data1;
        next = nullptr;
        back = nullptr;
    }
    static Node* Convert_to_Array_to_DLL(vector<int> arr){
        Node* head = new Node(arr[0]); // Always is First node is head
        Node* previ = head;
        
        for(int i =1 ; i< arr.size() ;i++){
            Node* temp = new Node(arr[i],nullptr,previ);
            previ->next = temp;
            previ = temp;
        }
        return head;
    }
};

Node* Insert_Before_Head(Node* head, int val){

    Node* NewHead = new Node(val,head,nullptr);
    head->back = NewHead;

    return NewHead;
}

Node* Insert_Before_toil(Node* head, int val){
    if(head == nullptr ){
        return new Node(val);
    }


    if(head->next == nullptr ){
        return Insert_Before_Head(head,val);
    }

    Node* last = head;
    while(last->next != nullptr){
        last = last->next;
    }
    Node* pre = last->back;
    Node* NewNode = new Node(val,last,pre);

    pre->next = NewNode;
    last->back= NewNode;

    return head;
}

Node* Insert_Before_Kth_ele(Node* head, int k,int val){
    if(k == 1){
        return Insert_Before_Head(head,val);
    }
    Node* temp = head;
    int cnt=0;
    while(temp != nullptr){
        cnt++;
        if(cnt == k){
            break;
        }
        temp = temp->next;
    }
    Node* pre = temp->back;
    Node* NewNode = new Node(val,temp,pre);
    pre->next = NewNode;
    temp->back = NewNode;
    return head;
}
void Insert_Before_Kth_ele(Node* node,int val){
    Node* pre = node->back;
    Node* NewNode = new Node(val,node,pre);
    pre->next = NewNode ;
    node->back = NewNode;
    
}


void print(Node* head){

    while(head != nullptr){
        cout<<head->data<<" ";
        head = head->next;
    }
}
int main(){
    vector<int> arr= {1,2,3,4,5};
    // it Initialize the value
    Node* head = Node::Convert_to_Array_to_DLL(arr);
    cout<<"Before Inserting DLL :";
    print(head);
    cout<<endl;

    // insert Head 
    // head =Insert_Before_Head(head,10);

    // insert before  last Node
    // head =Insert_Before_toil(head,10);

    // insert before Kth Node
    // head =Insert_Before_Kth_ele(head,4,100);

    // insert before Node
    Insert_Before_Kth_ele(head->next,60);

    cout<<endl<<"After Inserting DLL :";
    print(head);

    return 0;
}
