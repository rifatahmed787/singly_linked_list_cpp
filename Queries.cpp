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

void insert_at_head(Node *&head, Node *&tail, int v)
{
    Node *newNode = new Node(v);

    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
}

int size(Node *head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

void delete_from_head(Node *&head)
{
    if (head == NULL) return; 

    Node *deleteHead = head;
    head = head->next;
    delete deleteHead;
}

void delete_from_tail(Node *&head, Node *&tail)
{
    if (head == NULL) return; 

    if (head == tail)
    {
       
        delete head;
        head = NULL;
        tail = NULL;
        return;
    }

    Node *temp = head;
    while (temp->next != tail)
    {
        temp = temp->next;
    }

    delete tail;
    tail = temp;
    tail->next = NULL;
}

void delete_from_position(Node *&head, Node *&tail, int pos)
{
    if (pos >= size(head) || pos < 0) return;

    if (pos == 0)
    {
        delete_from_head(head);
        if (head == NULL) tail = NULL; 
        return;
    }

    if (pos == size(head) - 1)
    {
        delete_from_tail(head, tail);
        return;
    }

    Node *temp = head;
    for (int i = 1; i < pos; i++)
    {
        temp = temp->next;
        if (temp == NULL) return;
    }

    Node *deleteNode = temp->next;
    temp->next = temp->next->next;
    delete deleteNode;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    int t;
    cin >> t;

    while (t--)
    {
        int x;
        cin >> x;
        if (x == 0)
        {
            int v;
            cin >> v;
            insert_at_head(head, tail, v);
        }
        else if (x == 1)
        {
            int v;
            cin >> v;
            insert_at_tail(head, tail, v);
        }
        else if (x == 2)
        {
            int pos;
            cin >> pos;
            if (pos == 0)
            {
                delete_from_head(head);
                if (head == NULL) tail = NULL;
            }
            else if (pos == size(head) - 1)
            {
                delete_from_tail(head, tail);
            }
            else
            {
                delete_from_position(head, tail, pos);
            }
        }

        print_linked_list(head);
    }

    return 0;
}
