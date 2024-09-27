#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *prev;

    Node(int data)
    {
        val = data;
        next = nullptr;
        prev = nullptr;
    }
};
void InsertTail(Node *&head, Node *&tail, int val)
{
    Node *temp = new Node(val);

    if (!head)
    {
        head = temp;
        tail = temp;
        head->next = head;
        head->prev = head;
    }
    else
    {
        temp->prev = tail;
        temp->next = head;
        tail->next = temp;
        head->prev = temp;
        tail = temp;
    }
}

void Merge(Node *head1, Node *head2, Node *&ans_head, Node *&ans_tail)
{

    if (!head1 && !head2)
    {
        cout << "Empty Lists" << endl;
        return;
    }
    if (head1)
    {
        Node *ptr = head1;
        do
        {
            InsertTail(ans_head, ans_tail, head1->val);
            head1 = head1->next;
        } while (head1 != ptr);
    }
    if (head2)
    {

        Node *ptr = head2;
        do
        {
            InsertTail(ans_head, ans_tail, head2->val);
            head2 = head2->next;
        } while (head2 != ptr);
    }
}

void print(Node *head)
{
    if (!head)
        return;

    Node *ptr = head;
    do
    {
        cout << ptr->val << " ";
        ptr = ptr->next;
    } while (ptr != head);
    cout << endl;
}

int main()
{
    Node *head1 = nullptr;
    Node *tail1 = nullptr;
    Node *head2 = nullptr;
    Node *tail2 = nullptr;
    Node *ans_head = nullptr;
    Node *ans_tail = nullptr;

    InsertTail(head1, tail1, 1);
    InsertTail(head1, tail1, 6);
    InsertTail(head1, tail1, 8);
    InsertTail(head1, tail1, 0);

    InsertTail(head2, tail2, 3);
    InsertTail(head2, tail2, 7);
    InsertTail(head2, tail2, 9);

    cout << "List 1: ";
    print(head1);

    cout << "List 2: ";
    print(head2);

    cout << "Merged List : ";
    Merge(head1, head2, ans_head, ans_tail);
    print(ans_head);

    return 0;
}
