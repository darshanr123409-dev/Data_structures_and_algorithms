#include<bits/stdc++.h>
using namespace std;

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

Node* Delete_Head(Node* head){
    if(head == nullptr || head->next == nullptr){
        return nullptr;
    }
    Node* pre = head;
    head = head->next;
    head->back = nullptr;
    pre->next = nullptr;
    delete pre;

    return head;
}

Node* Delete_last_DLL(Node* head){
    if(head == nullptr)
        return nullptr;

    if(head->next == nullptr){
        delete head;
        return nullptr;
    }

    Node* tail = head;
    while(tail->next != nullptr){
        tail = tail->next;
    }

    Node* previous = tail->back;
    previous->next = nullptr;

    tail->back = nullptr;
    delete tail;

    return head;
}

Node* Delete_Kth_Element(Node* head , int k){
    if(head == nullptr){
        return nullptr;
    }
    Node* Kth_temp = head;
    int cnt =0;
    while(Kth_temp != nullptr){
        cnt++;
        if(cnt == k)
            break;
        Kth_temp = Kth_temp->next;
    }
    if (Kth_temp == nullptr)
        return head;


    Node* Previous = Kth_temp->back;
    Node* front = Kth_temp->next;

    if( Previous == nullptr && front == nullptr ){
        delete Kth_temp;
        return nullptr;
    }
    else if(Previous == nullptr){
        return Delete_Head(head);
    }
    else if(front == nullptr){
        return Delete_last_DLL(head);
    }
    Previous->next = front;
    front->back = Previous;
    
    Kth_temp->next = nullptr;
    Kth_temp->back = nullptr;

    delete Kth_temp;

    return head;

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
    cout<<"Before Deleting DLL :";
    print(head);
    cout<<endl;
    // Delete head
    // head = Delete_Head_DLL(head);

    // Delete Last
    head = Delete_last_DLL(head);

    // Delete Kth Element
    head = Delete_Kth_Element(head,2);

    cout<<endl<<"Before Deleting DLL :";
    print(head);

    return 0;
}
