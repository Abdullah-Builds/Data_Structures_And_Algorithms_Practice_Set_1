#include <iostream>
#include <cmath>
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

Node *Build_Tree(int arr[], int index, int size)
{
    if (index >= size)
        return NULL;
    Node *current = new Node(arr[index]);
    current->left = Build_Tree(arr, 2 * index + 1, size);
    current->right = Build_Tree(arr, 2 * index + 2, size);
    return current;
}

int Count(Node *current)
{
    if (current == NULL)
        return 0;
    return 1 + Count(current->left) + Count(current->right);
}

Node *ToFull(Node *current)
{
    if (current == NULL)
        return NULL;
    current->left = ToFull(current->left);
    current->right = ToFull(current->right);
    if (current->left == NULL && current->right != NULL)
    {
        delete current->right;
        current->right = NULL;
    }
    if (current->left != NULL && current->right == NULL)
    {
        delete current->left;
        current->left = NULL;
    }
    return current;
}

void Inorder_Traversal(Node *current)
{
    if (current == NULL)
        return;
    Inorder_Traversal(current->left);
    cout << current->val << " ";
    Inorder_Traversal(current->right);
}

bool isCheckComplete(Node *current, int index, int totalNodes)
{
    if (current == NULL)
        return true;
    if (index >= totalNodes)
        return false;
    return isCheckComplete(current->left, 2 * index + 1, totalNodes) &&
           isCheckComplete(current->right, 2 * index + 2, totalNodes);
}

bool isFull(Node *current)
{
    if (current == NULL)
        return true;
    if ((current->left == NULL && current->right) ||
        (current->left && current->right == NULL))
        return false;
    return isFull(current->left) && isFull(current->right);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int size = sizeof(arr) / sizeof(arr[0]);

    Node *root = Build_Tree(arr, 0, size);

    cout << "In-order Traversal of the Binary Tree: ";
    Inorder_Traversal(root);

    int total = Count(root);

    if (isCheckComplete(root, 0, total))
    {
        cout << "Complete  tree." << endl;
    }
    else
    {
        cout << "TNot a complete  tree." << endl;
    }
    if (isFull(root))
    {
        cout << "Full binary tree." << endl;
    }
    else
    {
        cout << "Not a full binary tree making  full." << endl;
        root = ToFull(root);
        cout << "Inorder traversal after making  tree full: ";
        Inorder_Traversal(root);

    }

}
