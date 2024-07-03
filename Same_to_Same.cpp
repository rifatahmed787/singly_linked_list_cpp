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

bool compare(Node *head1, Node *head2)
{
    bool flag = true;
    while (head1 != NULL && head2 != NULL)
    {
        if (head1->val != head2->val)
        {
            flag = false;
            break;
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    if(head1 == NULL && head2 == NULL){
        return flag;
    }else{
        return false;
    }
}

int main()
{
    int val1;
    Node *head1 = NULL;
    Node *tail1 = NULL;

    while (true)
    {
        cin >> val1;
        if (val1 == -1)
            break;

        insert_at_tail(head1, tail1, val1);
    }

    int val2;
    Node *head2 = NULL;
    Node *tail2 = NULL;

    while (true)
    {
        cin >> val2;

        if (val2 == -1)
            break;

        insert_at_tail(head2, tail2, val2);
    }

    if(compare(head1, head2)){
        cout<<"YES";
    }else{
        cout<<"NO";
    }
    return 0;
}