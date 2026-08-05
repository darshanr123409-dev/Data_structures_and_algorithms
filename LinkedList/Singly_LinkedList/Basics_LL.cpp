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
int Length_of_LL(Node* head){
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
int main(){
    vector<int> arr= {1,2,3,4,5};
    // it Initialize the value
    Node* head = Node::Convert_to_Array_to_LL(arr);
    cout<<head->data<<endl;
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<Length_of_LL(head);
    cout<<endl<<Checked_is_present(head,4);
    return 0;
}
