#include<bits/stdc++.h>
using namespace std;
 
class Node{
    public:
    int val;
    Node* next;

    Node(int val){
        this->val = val;
        this->next =NULL;
    };
};

int main(){
    Node* Head=new Node(10);
    Node* a=new Node(20);

    Head -> next=a;

    cout<< Head -> val << endl;
    cout << a -> val << endl;
    cout << (*(*Head).next).val << endl;
    cout << Head -> next->val << endl;
    return 0;
}