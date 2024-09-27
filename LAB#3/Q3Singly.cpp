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

void InsertTail(Node *&head, Node *&tail, int data)
{

    Node *temp = new Node(data);

     if (!head)
    {
        head = temp;
        tail = temp;
        tail->next = head; 
    }
    else
    {
        tail->next = temp;
        tail = temp;
        tail->next = head;
    }
}

void InsertHead(Node *&head, Node *&tail, int data)
{

    Node *temp = new Node(data);

    if (!head)
    {
        head = temp;
        tail = temp;
        tail->next = head;
    }

    else
    {
        temp->next = head;
        head = temp;
        tail->next = head;
    }
}

void InsertPos(Node *&head, Node *&tail, int data, int pos)
{

    if (pos <= 0)
    {
        cout << "Invalid" << endl;
        return;
    }

    Node *temp = new Node(data);

    if (pos == 1)
    {
        head = temp;
        tail = temp;
        tail->next = head;
    }
    else
    {
        Node *ptr = head;
        for (int i = 1; i < pos - 1 && ptr->next != tail; i++)
        {
            ptr = ptr->next;
        }

        temp->next = ptr->next;
        ptr->next = temp;

        if (ptr == tail)
        {
            tail = temp;
            tail->next = head;
        }
    }
}void print(Node *head)
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
void DeletePos(Node *&head, Node *&tail, int pos)
{
    if (!head || pos <= 0)
    {
        cout << "Invalid " << endl;
        return;
    }

    if (pos == 1)
    {
        Node *temp = head;
        if (head == tail)
        {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            head = head->next;
            tail->next = head;
        }
        delete temp;
    }
    else
    {
        Node *ptr = head;
        for (int i = 1; i < pos - 1 && ptr->next != head; i++)
        {
            ptr = ptr->next;
        }

        if (ptr->next == head)
        {
            cout << "Invalid" << endl;
            return;
        }

        Node *temp = ptr->next;
        ptr->next = temp->next;
        
        if (temp == tail)
        {
            tail = ptr;
            tail->next = head;
        }

        delete temp;
    }
}

int main()
{
    Node *head = nullptr;
    Node *tail = nullptr;

    InsertHead(head, tail, 1);
    InsertHead(head, tail, 2);
    InsertHead(head, tail, 3);
    InsertHead(head, tail, 4);
    InsertTail(head, tail, 5);
    InsertTail(head, tail, 6);
    InsertPos(head, tail, 7, 3);
    InsertPos(head, tail, 11, 4);
    InsertPos(head, tail, 9, 6);

    cout << "Original: ";
    print(head);

    DeletePos(head, tail, 3);
    DeletePos(head, tail, 1);

    cout << "After Deletion: ";
    print(head);

}
