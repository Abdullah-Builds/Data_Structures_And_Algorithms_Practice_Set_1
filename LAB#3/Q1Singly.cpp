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

void InsertHead(Node *&head, int data)
{

    Node *temp = new Node(data);

    temp->next = head;
    head = temp;
}

void InsertTail(Node *&head, int data)
{

    Node *temp = new Node(data);

    if (!head)
    {
        head = temp;
    }
    else
    {
        Node *ptr = head;
        while (ptr->next != nullptr)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}
void reverse(Node *&head)
{
    Node *forward = nullptr;
    Node *start = head;
    Node *prev = nullptr;

    while (start)
    {

        forward = start->next;
        start->next = prev;
        prev = start;
        start = forward;
    }
    head = prev;
}

void Insert(Node *&head, Node *&ans)
{

    if (!head)
    {
        cout << "Invalid" << endl;
    }
    else
    {
        Node *ptr = head;
        Node *even = nullptr;
        Node *odd = nullptr;

        while (ptr != nullptr)
        {

            if (ptr->val % 2 == 0)
            {
                InsertHead(even, ptr->val);
            }
            else
            {
                InsertHead(odd, ptr->val);
            }
            ptr = ptr->next;
        }

        if (!even)
        {
            ans = odd;
        }
        else if (!odd)
        {
            ans = even;
        }
        else
        {

            ans = even;
            Node *res = ans;
            while (res->next)
            {
                res = res->next;
            }
            res->next = odd;
        }
    }
}

void print(Node *head)
{
    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{

    Node *ans = nullptr;
    Node *head = new Node(17);
    head->next = new Node(15);
    head->next->next = new Node(8);
    head->next->next->next = new Node(12);
    head->next->next->next->next = new Node(10);
    head->next->next->next->next->next = new Node(5);
    head->next->next->next->next->next->next = new Node(4);
    head->next->next->next->next->next->next->next = new Node(1);
    head->next->next->next->next->next->next->next->next = new Node(7);
    head->next->next->next->next->next->next->next->next->next = new Node(6);

    cout << "Original : ";
    print(head);
    reverse(head);

    Insert(head, ans);

    cout << "Odd Even : ";
    print(ans);
}
