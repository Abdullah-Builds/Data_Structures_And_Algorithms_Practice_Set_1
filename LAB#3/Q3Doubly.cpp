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

void swap(Node *&ptr1, Node *&ptr2, Node *&head, Node *&tail)
{
    if (ptr1 == ptr2) return;

    Node *temp1 = ptr1->next;
    Node *prev1 = ptr1->prev;
    Node *temp2 = ptr2->next;
    Node *prev2 = ptr2->prev;

    if (ptr1 == head) head = ptr2;
    else if (ptr2 == head) head = ptr1;

    if (ptr1 == tail) tail = ptr2;
    else if (ptr2 == tail) tail = ptr1;

    if (temp1 == ptr2)
    {
        ptr1->next = temp2;
        ptr1->prev = ptr2;
        ptr2->next = ptr1;
        ptr2->prev = prev1;

        if (temp2) temp2->prev = ptr1;
        if (prev1) prev1->next = ptr2;
    }
    else if (temp2 == ptr1)
    {
        ptr2->next = temp1;
        ptr2->prev = ptr1;
        ptr1->next = ptr2;
        ptr1->prev = prev2;

        if (temp1) temp1->prev = ptr2;
        if (prev2) prev2->next = ptr1;
    }
    else
    {
        ptr1->next = temp2;
        ptr1->prev = prev2;
        ptr2->next = temp1;
        ptr2->prev = prev1;

        if (temp1) temp1->prev = ptr2;
        if (prev1) prev1->next = ptr2;
        if (temp2) temp2->prev = ptr1;
        if (prev2) prev2->next = ptr1;
    }

    head->prev = tail;
    tail->next = head;
}

void solve(Node *&head, Node *&tail, int pos1, int pos2)
{
    if (pos1 == pos2) return;

    Node *ptr1 = head;
    Node *ptr2 = head;

    int length = 1;
    while (ptr1->next != head) 
    {
        length++;
        ptr1 = ptr1->next;
    }

    if (pos1 < 1 || pos2 < 1 || pos1 > length || pos2 > length)
    {
        cout << "Invalid " << endl;
        return;
    }

    ptr1 = head;
    ptr2 = head;

    for (int i = 1; i < pos1; i++)
    {
        ptr1 = ptr1->next;
    }

    for (int i = 1; i < pos2; i++)
    {
        ptr2 = ptr2->next;
    }

    swap(ptr1, ptr2, head, tail);
}

void print(Node *head)
{
    if (!head) return;

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
    Node *head = nullptr;
    Node *tail = nullptr;

    InsertTail(head, tail, 1);
    InsertTail(head, tail, 2);
    InsertTail(head, tail, 3);
    InsertTail(head, tail, 6);
    InsertTail(head, tail, 10);

    char choice;
    do
    {
        cout << "List before swap: ";
        print(head);

        int pos1, pos2;
        cout << "Enter position 1 and position 2: ";
        cin >> pos1 >> pos2;

        solve(head, tail, pos1, pos2);

        cout << "After swapping: ";
        print(head);

        cout << "Continue (y or n): ";
        cin >> choice;
    } while (choice == 'y');
}
