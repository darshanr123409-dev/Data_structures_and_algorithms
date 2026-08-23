#include <bits/stdc++.h>
using namespace std;

// Node class for the doubly linked list
class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    // Constructor to initialize node with a value
    Node(int val)
    {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

// Solution class containing all operations on the doubly linked list
class Solution
{
public:
    // Inserts a new node with the given value at the end of the list
    void insertAtEnd(Node *&head, int val)
    {
        // Create the new node
        Node *newNode = new Node(val);

        // If list is empty, set new node as head
        if (!head)
        {
            head = newNode;
            return;
        }

        // Traverse to the last node
        Node *temp = head;
        while (temp->next)
            temp = temp->next;

        // Link the new node at the end
        temp->next = newNode;
        newNode->prev = temp;
    }

    // Prints the entire linked list from head to tail
    void printList(Node *head)
    {
        // Start from the head node
        Node *temp = head;

        // Traverse and print each node's data
        while (temp)
        {
            cout << temp->data;
            if (temp->next)
                cout << " <-> ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Deletes all nodes that have the specified target value
    Node *deleteTargetNodes(Node *head, int target)
    {
        // Start from the head node
        Node *current = head;

        // Traverse the entire list
        while (current != nullptr)
        {
            // Store next node before possibly deleting current
            Node *nextNode = current->next;

            // If current node matches the target value
            if (current->data == target)
            {
                // If not the head, link previous node to next
                if (current->prev)
                    current->prev->next = current->next;
                else
                    // If it's the head, move head forward
                    head = current->next;

                // If not the tail, link next node to previous
                if (current->next)
                    current->next->prev = current->prev;

                // Delete the current node
                delete current;
            }

            // Move to the next node
            current = nextNode;
        }

        // Return updated head
        return head;
    }
};
