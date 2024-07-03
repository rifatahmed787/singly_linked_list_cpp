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

void remove_duplicate(Node *&head)
{
    if (head == NULL) return;

    Node *temp = head;

    while (temp != NULL && temp->next != NULL)
    {
        Node *dupli = temp;
        while (dupli->next != NULL)
        {
            if (dupli->next->val == temp->val)
            {
                Node *duplicateNode = dupli->next;
                dupli->next = dupli->next->next;
                delete duplicateNode;
            }
            else
            {
                dupli = dupli->next;
            }
        }
        temp = temp->next;
    }
}

void print_linked_list(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
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

    remove_duplicate(head);
    print_linked_list(head);

    return 0;
}
