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

void reverse(Node *&head, Node *&tail)
{
    if (!head || !head->next)
    {
        return;
    }

    Node *curr = head;
    Node *temp = nullptr;

    do
    {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    } while (curr != head);

    if (temp != nullptr)
    {
        tail = head;
        head = temp->prev;
    }

    head->prev = tail;
    tail->next = head;
}

void print(Node *head, Node *tail)
{
    Node *temp = head;
    do
    {
        cout << temp->val << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

void solve(Node *&head, Node *&tail)
{
    Node *temp_head = nullptr;
    Node *temp_tail = nullptr;
    Node *ptr = head;
    Node *prev = nullptr;
    int count = 1;

    do
    {
        if (count % 2 == 0)
        {
            InsertTail(temp_head, temp_tail, ptr->val);

            Node *to_delete = ptr;
            prev->next = ptr->next;
            ptr->next->prev = prev;

            if (to_delete == head)
                head = head->next;
            if (to_delete == tail)
                tail = prev;

            ptr = ptr->next;

            delete to_delete;
        }
        else
        {
            prev = ptr;
            ptr = ptr->next;
        }
        count++;
    } while (ptr != head);

    if (temp_head)
    {
        reverse(temp_head, temp_tail);

        prev->next = temp_head;
        temp_head->prev = prev;
        temp_tail->next = head;
        head->prev = temp_tail;
    }
}

int main()
{
    Node *head = nullptr;
    Node *tail = nullptr;

    InsertTail(head, tail, 10);
    InsertTail(head, tail, 4);
    InsertTail(head, tail, 9);
    InsertTail(head, tail, 1);
    InsertTail(head, tail, 3);
    InsertTail(head, tail, 5);
    InsertTail(head, tail, 9);
    InsertTail(head, tail, 4);

    cout << "Original List: ";
    print(head, tail);

    solve(head, tail);

    cout << "Modified List: ";
    print(head, tail);
}
