#include<bits/stdc++.h>
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

void insert_at_tail(Node *&head, int v)
{

    Node *newNode = new Node(v);

    if (head == NULL)
    {
        head = newNode;
        cout << "inserted at head" << endl;
        return;
    };
    Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    cout << "inserted at tail" << endl;
};

void print_linked_list(Node *head)
{

    cout <<endl<< "Your linked list:";

    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    };
    cout << endl;
};
int main(){
    int val;
    Node *head=NULL;

    while(true){
        cout<<"enter the value: ";
        cin >> val;
        if(val==-1) break;

        insert_at_tail(head,val);
    }
    print_linked_list(head);
    return 0;
}