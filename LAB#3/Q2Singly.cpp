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

bool isPalindrome(Node *&head)
{
    if (!head || !head->next)
    {
        return true;
    }

    Node *slow = head;
    Node *fast = head;

    // Middle Node
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse
    Node *forward = nullptr;
    Node *start = head;
    Node *prev = nullptr;

    while (start != slow)
    {

        forward = start->next;
        start->next = prev;
        prev = start;
        start = forward;
    }

//if odd num of nodes
    if (fast)
    {
        slow = slow->next;
    }

    Node *firstHalf = prev;
    Node *secondHalf = slow;

    while (firstHalf && secondHalf)
    {
        if (firstHalf->val != secondHalf->val)
        {
            return false;
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    return true;
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

    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(2);
    head->next->next->next = new Node(1);
    
    print(head);
    if (!isPalindrome(head))
    {
        cout << "Is Not Palindrome" << endl;
    }
    else
    {
        cout << "Palindrome" << endl;
    }

}
