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

int solve(  Node*head, int count){
    if( !head ) return count;
    return solve(head->next,count+1);
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

    int count = 0;
    print(head);
    cout <<  "Singly Linked List Count : " <<  solve(head,count) << endl;
}

