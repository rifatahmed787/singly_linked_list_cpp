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

void insert_at_tail(Node *&head, int v)
{
    Node *newNode = new Node(v);

    if (head == NULL)
    {
        head = newNode;
        cout<<"inserted at head"<<endl;
        return;
    };
    Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    cout<< "inserted at tail"<< endl;
}
void print_linked_list(Node *head)
{
    cout << "Your linked list:";
    
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val<<" ";
        temp = temp->next;
    };
    cout<<endl;
};

void insert_at_position(Node *head, int pos, int v){
    Node *temp = head;
    Node *newNode=new Node(v);

    for(int i=1; i<=pos-1; i++){
       temp=temp->next;
    };
    newNode->next=temp->next;
    temp->next=newNode;

    cout<<endl<<"Positon inserted"<<endl<<endl;
};
int main()
{

    Node *head = NULL;

    while (true)
    {

        cout << "Option 1: insert at tail" << endl;
        cout << "Option 2: Print linked list" << endl;
        cout << "Option 3: insert at position" << endl;
        cout << "Option 4: terminate" << endl;
        int op;
        cin >> op;
        if (op == 1)
        {
            cout << "Please enter a value :";
            int v;

            cin >> v;
            insert_at_tail(head, v);
        }
        else if (op == 2)
        {

            print_linked_list(head);
        }else if(op == 3){
            int pos, v;
            cout<<"enter a position:";
            cin >> pos;
            cout<<"enter a value:";
            cin >> v;

            insert_at_position(head, pos, v);

        }
        else if (op == 4)
        {
            break;
        };
    };
    return 0;
}