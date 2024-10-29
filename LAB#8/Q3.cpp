#include <iostream>
using namespace std;

int counter = 0;   // foe the size of tree
 
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

class Node
{
public:
    int val;
    Node *left;
    Node *right;
       Node(int value)
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

bool Searching(Node *root, int value)
{
    if (!root)
        return false;

    Queue<Node *> q(counter);
    q.enqueue(root);

    while (!q.empty())
    {
        Node *current = q.front();
        q.dequeue();

        if (current->val == value)
        {
            return true;
        }
        if (current->left)
            q.enqueue(current->left);
        if (current->right)
            q.enqueue(current->right);
    }
    return false;
}
Node *InsertAfter(Node *root, int value)
{
    if (!root)
    {
        cout << "Inserted " << value << " as the root at level 0." << endl;
        return new Node(value);
    }

    if (value < root->val)
    {
        if (!root->left)
        {
            root->left = new Node(value);
            cout << "Inserted " << value << " as left child." << endl;
        }
        else
        {
            InsertAfter(root->left, value);
        }
    }
    else if (value > root->val)
    {
        if (!root->right)
        {
            root->right = new Node(value);
            cout << "Inserted " << value << " as right child." << endl;
        }
        else
        {
            InsertAfter(root->right, value);
        }
    }
    else
    {
        cout << "Value " << value << " already exists " << endl;
    }
    return root;
}
Node *Built_Tree(Node *&root, int data)
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
    In_Order_Traversal(root);

    int value;
    cout << "Enter a value to search and if it does not exist insert it : " << endl;
    cin >> value;

    if (Searching(root, value))
    {
        cout << "Value " << value << " already exists " << endl;
    }
    else
    {
        cout << "Not Found : " << endl;
        root = InsertAfter(root, value);
        In_Order_Traversal(root);
    }
}
