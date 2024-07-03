#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next = NULL;

    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    };
};

void insert_at_tail(Node *&head, Node *&tail, int v)
{
    Node *newNode = new Node(v);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }

    tail->next = newNode;
    tail = newNode;
}

int get_maximum(Node *head)
{
    Node *temp = head;
    int max = temp->val;
    while (temp != NULL)
    {
        if (temp->val > max)
        {
            max = temp->val;
        }
        temp=temp->next;
    }
    return max;
}

int get_minimum(Node *head){
     Node *temp=head;
     int min=temp->val;
     while(temp!=NULL){
        if(temp->val < min){
            min=temp->val;
        }
        temp=temp->next;
     }

     return min;
}


int main()
{
    int val;
    Node *head = NULL;
    Node *tail = NULL;

    while (true)
    {
        cin >> val;
        if (val == -1)
            break;

        insert_at_tail(head, tail, val);
    }

    cout<<get_maximum(head)-get_minimum(head);
     
    
    return 0;
}