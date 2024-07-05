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
    }
};


void reverse(Node *&head, Node *current){
    if(current->next==NULL){
        head=current;
        return;
    }
    reverse(head, current->next);
    current->next->next=current;
    current->next=NULL;
}

void print_reverse(Node *head){
    Node *temp=head;
    while(temp!=NULL){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
}

int main()
{

    Node *head = new Node(10);
    Node *a=new Node(20);
    Node *b=new Node(30);

    head->next=a;
    a->next=b;
    b->next=NULL;


    reverse(head, head);
    print_reverse(head);
    return 0;
}