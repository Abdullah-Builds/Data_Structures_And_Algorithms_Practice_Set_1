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
void InorderTraversal(Node *root, int arr[], int &index)
{
    if (root == NULL)
        return;
    InorderTraversal(root->left, arr, index);
    arr[index++] = root->val;
    InorderTraversal(root->right, arr, index);
}
void Merge(int arr1[], int s1, int arr2[], int s2, int merge[])
{
    int r = 0;
    int c = 0;
    int tp = 0;

    while (r < s1 && c < s2)
    {
        if (arr1[r] < arr2[c])
            merge[tp++] = arr1[r++];
        else
            merge[tp++] = arr2[c++];
    }
    while (r < s1)
        merge[tp++] = arr1[r++];
    while (c < s2)
        merge[tp++] = arr2[c++];
}

Node *Solve(int arr[], int start, int end)
{
    if (start > end)
        return NULL;
    int mid = (start + end) / 2;
    Node *node = new Node(arr[mid]);
    node->left = Solve(arr, start, mid - 1);
    node->right = Solve(arr, mid + 1, end);
    return node;
}
void Inorder_Traversal(Node *root)
{
    if (root == NULL)
        return;
    Inorder_Traversal(root->left);
    cout << root->val << " ";
    Inorder_Traversal(root->right);
}

int main()
{
    Node *root1 = new Node(5);
    root1->left = new Node(3);
    root1->right = new Node(6);
    root1->left->left = new Node(2);
    root1->left->right = new Node(4);

    cout << "BST1 : " << endl;
    Inorder_Traversal(root1);

    Node *root2 = new Node(2);
    root2->left = new Node(1);
    root2->right = new Node(3);
    root2->right->right = new Node(7);
    root2->right->right->left = new Node(6);

    cout << "BST2 : ";
    Inorder_Traversal(root2);

    int arr1[5];
    int arr2[5];
    int index1 = 0;
    int index2 = 0;

    InorderTraversal(root1, arr1, index1);
    InorderTraversal(root2, arr2, index2);

    int merge[10];

    Merge(arr1, index1, arr2, index2, merge);
    Node *MergeBST = Solve(merge, 0, 9);

    cout << endl
         << "Merged BST: ";
    Inorder_Traversal(MergeBST);
}