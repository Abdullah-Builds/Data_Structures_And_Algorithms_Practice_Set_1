#include <iostream>
#include<cmath>
using namespace std;

int counter = 0; // For the size of tree

class Node
{
public:
    double val;
    Node *left;
    Node *right;

    Node(double value)
    {
        val = value;
        left = nullptr;
        right = nullptr;
    }
    Node()
    {
        left = nullptr;
        right = nullptr;
    }
};

template <typename T>
class Queue
{
    int qfront;
    int qrear;
    int size;
    T *arr;

public:
    Queue(int s) : qfront(0), qrear(0), size(s)
    {
        arr = new T[size];
    }

    ~Queue()
    {
        delete[] arr;
    }

    void enqueue(T val)
    {
        if (qrear == size)
        {
            cout << "Queue Overflow" << endl;
        }
        else
        {
            arr[qrear] = val;
            qrear++;
        }
    }

    void dequeue()
    {
        if (qrear == qfront)
        {
            cout << "Queue is Empty" << endl;
        }
        else
        {
            qfront++;

            if (qfront == qrear)
            {
                qfront = 0;
                qrear = 0;
            }
        }
    }

    T front()
    {
        if (qfront == qrear)
        {
            cout << "Queue is Empty" << endl;
            return T();
        }
        else
        {
            return arr[qfront];
        }
    }

    bool empty()
    {
        return qfront == qrear;
    }
};

void Search(Node *root, int target, int Size)
{

    Queue<Node*> q(Size);
    q.enqueue(root);
    bool found = false;

    while (!q.empty())
    {
        Node *curr = q.front();
        q.dequeue();
        if (curr->val == target)
        {
            cout << "Value Found : " << curr->val << endl;
            found = true;
        }
        if (curr->left)
            q.enqueue(curr->left);
        if (curr->right)
            q.enqueue(curr->right);
    }

    if (!found)
        cout << "Not found" << endl;
}

Node *Built_Tree(Node *&root, double data)
{
    if (root == nullptr)
    {
        return root = new Node(data);
    }
    if (data < root->val)
    {
        root->left = Built_Tree(root->left, data);
    }
    else if (data > root->val)
    {
        root->right = Built_Tree(root->right, data);
    }
    return root;
}

void Insertion(Node *&root)
{
    double data;
    while (true)
    {
        cout << "Enter Data (-1 to stop): ";
        cin >> data;
        if (data == -1)
            break;
        counter++;
        Built_Tree(root, data);
    }
}

void In_Order_Traversal(Node *root)
{

    if (root == nullptr)
        return;

    In_Order_Traversal(root->left);
    cout << root->val << " ";
    In_Order_Traversal(root->right);
}

int main()
{
    Node *root = nullptr;
    Insertion(root);

    float x;
    int ch;
    cout << "Enter value to Search: ";
    cin >> x;
    cout << "Choose ceil(2) or floor(1): ";
    cin >> ch;

    double target;
    if (ch == 2)
    {
        target = ceil(x);
        cout << "Ceil : " << target << endl;
    }
    else if( ch == 1)
    {
        target = floor(x);
        cout << "Floor : " << target << endl;
    }
    else{
        cout << "Invalid : ";
    }

    In_Order_Traversal(root);
    Search(root, target, counter);
}
