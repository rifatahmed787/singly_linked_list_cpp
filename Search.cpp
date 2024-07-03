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

int size(Node *head){
    Node *temp=head;

    int count = 0;
    while(temp != NULL){
        count ++;
        temp = temp->next;
    }

    return count;
}

int get_index(Node *head, int v)
{
    Node *temp = head;
    int index= 0;
    while (temp != NULL)
    {
       if(temp->val==v){
        break;
       }
       temp=temp->next;
       index++;
    }

    if(size(head)==index){
        return -1;
    }
    return index;
}


int main()
{
    int T;
    cin >> T;
    while (T--)
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

        int x;
        cin >> x;
        cout<<get_index(head, x)<<endl;
    }
    return 0;
}