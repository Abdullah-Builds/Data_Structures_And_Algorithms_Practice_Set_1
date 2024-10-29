#include <iostream>
using namespace std;

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

void Insertion(Node *&root, int* arr, int s)
{
    int count = 0;
    while (count < s)
    {
        Built_Tree(root, arr[count++]);
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
    int arr[] = {1,2,3,4,5};
    int s = 5;
    Insertion(root,arr,s);

    cout << "Inorder Traversal for printing : " << endl;
    In_Order_Traversal(root);

}
