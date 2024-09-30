#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *next;

    Node(int data)
    {
        val = data;
        next = nullptr;
    }
};

bool solve(Node* head,int target){

    if( !head ) return false;
    if( head->val == target ) return true;

    return solve(head->next,target);
}

void print(Node *head)
{
    while (head)
    {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main()
{

    Node *head = new Node(17);
    head->next = new Node(15);
    head->next->next = new Node(8);
    head->next->next->next = new Node(12);
    head->next->next->next->next = new Node(10);
    head->next->next->next->next->next = new Node(5);

    int target = 10;
    print(head);
    bool found = solve( head,target );

    if( found ){
        cout << "Target Found : " << target << endl;
    }
    else{
        cout <<"Target Not Found : " << endl;
    }
}

