#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int val)
    {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

class Solution
{
public:

    void insertAtEnd(Node *&head, int val)
    {
        Node *newNode = new Node(val);

        if (!head)
        {
            head = newNode;
            return;
        }

        Node *temp = head;

        while (temp->next)
        {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->prev = temp;
    }

    void printList(Node *head)
    {
        Node *temp = head;

        while (temp)
        {
            cout << temp->data;

            if (temp->next)
                cout << " <-> ";

            temp = temp->next;
        }

        cout << endl;
    }

    Node* find_last_node(Node* head)
    {
        Node* temp = head;

        while (temp != nullptr && temp->next != nullptr)
        {
            temp = temp->next;
        }

        return temp;
    }

    vector<vector<int>> findPairsWithGivenSum(Node* head, int target)
    {
        vector<vector<int>> ans;

        if (head == nullptr)
            return ans;

        Node* left = head;
        Node* right = find_last_node(head);

        while (left != nullptr &&
               right != nullptr &&
               left != right &&
               left != right->next)
        {
            int sum = left->data + right->data;

            if (sum == target)
            {
                ans.push_back({left->data, right->data});

                left = left->next;
                right = right->prev;
            }
            else if (sum < target)
            {
                left = left->next;
            }
            else
            {
                right = right->prev;
            }
        }

        return ans;
    }
};