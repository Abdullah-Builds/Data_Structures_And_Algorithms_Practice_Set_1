#include <iostream>
#include <string>
using namespace std;

struct Node
{
    char ch;
    int freq;
    Node *left;
    Node *right;

    Node(char c, int f) : ch(c), freq(f), left(NULL), right(NULL) {}
};

class MinHeap
{
public:
    Node *heap[100];
    int size;

    MinHeap() : size(0) {}

    void heapifyUp(int index)
    {
        while (index > 0)
        {
            int parent = (index - 1) / 2;

            if (heap[parent]->freq > heap[index]->freq)
            {
                swap(heap[parent], heap[index]);
                index = parent;
            }
            else
            {
                break;
            }
        }
    }

    void heapifyDown(int index)
    {
        while (index < size)
        {
            int smallest = index;
            int leftChild = 2 * index + 1;
            int rightChild = 2 * index + 2;

            if (leftChild < size && heap[leftChild]->freq < heap[smallest]->freq)
                smallest = leftChild;
            if (rightChild < size && heap[rightChild]->freq < heap[smallest]->freq)
                smallest = rightChild;

            if (smallest != index)
            {
                swap(heap[index], heap[smallest]);
                index = smallest;
            }
            else
            {
                break;
            }
        }
    }

    void insert(Node *node)
    {
        heap[size] = node;
        int index = size;
        size++;
        heapifyUp(index);
    }

    Node *extractMin()
    {
        if (size == 0)
            return NULL;

        Node *minNode = heap[0];
        swap(heap[0], heap[size - 1]);
        size--;
        heapifyDown(0);
           
        return minNode;
    }
};

void calculateFrequencies(string str, char characters[], int freq[], int &n)
{
    bool visited[256] = {false};

    for (char c : str)
    {
        if (!visited[c])
        {
            characters[n] = c;
            freq[n] = 0;

            for (char ch : str)
            {
                if (ch == c)
                    freq[n]++;
            }

            visited[c] = true;
            n++;
        }
    }
}

Node *buildHuffmanTree(char characters[], int freq[], int n)
{
    MinHeap minHeap;

    for (int i = 0; i < n; i++)
    {
        minHeap.insert(new Node(characters[i], freq[i]));
    }

    while (minHeap.size > 1)
    {
        Node *left = minHeap.extractMin();
        Node *right = minHeap.extractMin();

        Node *newNode = new Node('$', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;

        minHeap.insert(newNode);
    }

    return minHeap.extractMin();
}

void generateCodes(Node *root, string code, string huffmanCodes[], char characters[], int n)
{
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL)
    {
        for (int i = 0; i < n; i++)
        {
            if (characters[i] == root->ch)
            {
                huffmanCodes[i] = code;
                break;
            }
        }
        return;
    }

    generateCodes(root->left, code + "0", huffmanCodes, characters, n);
    generateCodes(root->right, code + "1", huffmanCodes, characters, n);
}

string encodeString(string str, char characters[], string huffmanCodes[], int n)
{
    string encodedStr = "";

    for (char c : str)
    {
        for (int i = 0; i < n; i++)
        {
            if (characters[i] == c)
            {
                encodedStr += huffmanCodes[i];
                break;
            }
        }
    }

    return encodedStr;
}

string decodeString(string encodedStr, Node *root)
{
    string decodedStr = "";
    Node *current = root;

    for (char bit : encodedStr)
    {
        if (bit == '0')
            current = current->left;
        else
            current = current->right;

        if (current->left == NULL && current->right == NULL)
        {
            decodedStr += current->ch;
            current = root;
        }
    }

    return decodedStr;
}

int main()
{
    string input = "Sameer Faisal";

    char characters[256];
    int freq[256];
    int n = 0;
    calculateFrequencies(input, characters, freq, n);

    Node *root = buildHuffmanTree(characters, freq, n);

    string huffmanCodes[256];
    generateCodes(root, "", huffmanCodes, characters, n);

    string encodedString = encodeString(input, characters, huffmanCodes, n);

    cout << "Huffman Codes:\n";
    for (int i = 0; i < n; i++)
    {
        cout << characters[i] << ": " << huffmanCodes[i] << "\n";
    }

    cout << "\nEncoded String: " << encodedString << "\n";

    string decodedString = decodeString(encodedString, root);
    cout << "\nDecoded String: " << decodedString << "\n";

    return 0;
}