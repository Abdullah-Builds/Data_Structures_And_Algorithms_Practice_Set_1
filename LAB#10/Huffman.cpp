#include <iostream>
#include <string>
using namespace std;

class TreeNode
{
public:
    char character;
    int frequency;
    TreeNode *leftChild;
    TreeNode *rightChild;

    TreeNode(char c, int f) {
        character = c;
        frequency = f;
        leftChild = nullptr;
        rightChild = nullptr;
    }

    TreeNode() {
        leftChild = nullptr;
        rightChild = nullptr;
    }
};

class PriorityQueue
{
public:
    TreeNode *heap[100];
    int heapSize;

    PriorityQueue() : heapSize(0) {}

    void shiftUp(int index)
    {
        while (index > 0)
        {
            int parent = (index - 1) / 2;
            if (heap[parent]->frequency > heap[index]->frequency)
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

    void shiftDown(int index)
    {
        while (index < heapSize)
        {
            int smallest = index;
            int leftChild = 2 * index + 1;
            int rightChild = 2 * index + 2;

            if (leftChild < heapSize && heap[leftChild]->frequency < heap[smallest]->frequency)
                smallest = leftChild;
            if (rightChild < heapSize && heap[rightChild]->frequency < heap[smallest]->frequency)
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

    void Insertion(TreeNode *node)
    {
        heap[heapSize] = node;
        int index = heapSize;
        heapSize++;
        shiftUp(index);
    }

    TreeNode *extractMin()
    {
        if (heapSize == 0)
            return nullptr;

        TreeNode *minNode = heap[0];
        swap(heap[0], heap[heapSize - 1]);
        heapSize--;
        shiftDown(0);

        return minNode;
    }
};

void calculatefrequency(string inputString, char uniqueChars[], int frequency[], int &uniqueCount)
{
    bool visited[256] = {false};

    for (char c : inputString)
    {
        if (!visited[c])
        {
            uniqueChars[uniqueCount] = c;
            frequency[uniqueCount] = 0;

            for (char ch : inputString)
            {
                if (ch == c)
                    frequency[uniqueCount]++;
            }

            visited[c] = true;
            uniqueCount++;
        }
    }
}

string encodeMsg(string inputString, char uniqueChars[], string huffmanCodes[], int uniqueCount)
{
    string encode = "";

    for (char c : inputString)
    {
        for (int i = 0; i < uniqueCount; i++)
        {
            if (uniqueChars[i] == c)
            {
                encode += huffmanCodes[i];
                break;
            }
        }
    }

    return encode;
}

string decodeMessage(string encodedString, TreeNode *root)
{
    string decode = "";
    TreeNode *current = root;

    for (char chh : encodedString)
    {
        if (chh == '0')
            current = current->leftChild;
        else
            current = current->rightChild;

        if (current->leftChild == nullptr && current->rightChild == nullptr)
        {
            decode += current->character;
            current = root;
        }
    }

    return decode;
}
TreeNode *Huffman_Build(char uniqueChars[], int frequency[], int uniqueCount)
{
    PriorityQueue minHeap;

    for (int i = 0; i < uniqueCount; i++)
    {
        minHeap.Insertion(new TreeNode(uniqueChars[i], frequency[i]));
    }

    while (minHeap.heapSize > 1)
    {
        TreeNode *left = minHeap.extractMin();
        TreeNode *right = minHeap.extractMin();

        TreeNode *newNode = new TreeNode('$', left->frequency + right->frequency);
        newNode->leftChild = left;
        newNode->rightChild = right;

        minHeap.Insertion(newNode);
    }

    return minHeap.extractMin();
}

void Generate_Code(TreeNode *root, string code, string huffmanCodes[], char uniqueChars[], int uniqueCount)
{
    if (root == nullptr)
        return;

    if (root->leftChild == nullptr && root->rightChild == nullptr)
    {
        for (int i = 0; i < uniqueCount; i++)
        {
            if (uniqueChars[i] == root->character)
            {
                huffmanCodes[i] = code;
                break;
            }
        }
        return;
    }

    Generate_Code(root->leftChild, code + "0", huffmanCodes, uniqueChars, uniqueCount);
    Generate_Code(root->rightChild, code + "1", huffmanCodes, uniqueChars, uniqueCount);
}


int main()
{
    string string_ = "sameer_faisal";

    char uniqueChars[256];
    int frequency[256];
    int uniqueCount = 0;
    calculatefrequency(string_, uniqueChars, frequency, uniqueCount);

    TreeNode *node = Huffman_Build(uniqueChars, frequency, uniqueCount);

    string huffman[256];
    Generate_Code(node, "", huffman, uniqueChars, uniqueCount);

    string encodedMessage = encodeMsg(string_, uniqueChars, huffman, uniqueCount);

    cout << "Huffman Codes : " << endl;
    for (int i = 0; i < uniqueCount; i++)
    {
        cout << uniqueChars[i] << " : " << huffman[i] << endl;
    }

    cout << endl << "Encoded sameer_fasial: " << encodedMessage << endl;

    string decodedstr = decodeMessage(encodedMessage, node);
    cout << endl << "Decoded sameer_faisal : " << decodedstr << endl;

}
