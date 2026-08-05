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

int Length_of_DLL(Node* head){
    int cnt=0;
    Node* temp = head;
    while(temp != NULL){
        temp = temp->next;
        cnt++;
    }
    return cnt;
}

int Checked_is_present(Node* head , int val){
    Node* temp = head;
    while(temp != NULL){
        if(temp->data==val){
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

void printDLL(Node* head){

    while(head != nullptr){
        cout<<head->data<<" ";
        head = head->next;
    }

}

int main(){
    vector<int> arr= {1,2,3,4,5};
    // it Initialize the value
    Node* head = Node::Convert_to_Array_to_DLL(arr);
    cout << "Before Doubly linked list : ";
    printDLL(head);
    
    cout<<endl;
    cout<<"Length of Doubly linked list : "<<Length_of_DLL(head)<<endl;
    cout<<"Checked_is_present : "<<Checked_is_present(head,4);    

    cout <<endl<< "After Doubly linked list : ";
    printDLL(head);

    return 0;
}
