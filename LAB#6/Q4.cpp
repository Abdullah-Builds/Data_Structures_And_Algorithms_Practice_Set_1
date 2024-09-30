#include <iostream>
using namespace std;

class Node
{
public:
    int value;
    Node *next;
    int pos = 0;

    Node(int val)
    {
        pos = 0;
        value = val;
        next = nullptr;
    }
    Node(int val, int p)
    {
        pos = p;
        value = val;
        next = nullptr;
    }
    Node()
    {
        value = -1;
        next = nullptr;
    }
};
void Insert_Head(Node *&head, int val, int position = 0)
{

    Node *temp = new Node(val, position);
    temp->next = head;
    head = temp;
}

void Insert_Tail(Node *&head, int val, int position = 0)
{
    if (!head)
    {
        Insert_Head(head, val, position);
        return;
    }
    Node *temp = new Node(val, position);
    Node *node = head;

    while (node->next != nullptr)
    {
        node = node->next;
    }
    node->next = temp;
}
void InsertInSorted(Node *&head, int data, int pos)
{
    Node *newNode = new Node(data, pos);

    if (!head || data > head->value)
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node *current = head;
    while (current->next != nullptr && current->next->value > data)
    {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

class Task
{
public:
    Node *CPU;
    Node *ExeTime;
    Node *Memory;
    Node *Storage;

    Task()
    {
        CPU = nullptr;
        ExeTime = nullptr;
        Memory = nullptr;
        Storage = nullptr;
    }
    void enqueueCPU(int *arr, int size)
    {
        for (int i = 0; i < size; i++)
        {
            Insert_Head(CPU, arr[i]);
        }
    }
    void enqueueExeTime(int *arr, int size)
    {
        for (int i = 0; i < size; i++)
        {
            Insert_Head(ExeTime, arr[i]);
        }
    }
    void enqueueMemory(int *arr, int size)
    {
        for (int i = 0; i < size; i++)
        {
            Insert_Head(Memory, arr[i]);
        }
    }
    void enqueueStorage(int *arr, int size)
    {
        for (int i = 0; i < size; i++)
        {
            Insert_Head(Storage, arr[i]);
        }
    }

    int dequeueCPU()
    {
        if (CPU == nullptr)
        {
            cout << "CPU queue is empty" << endl;
            return -1;
        }
        Node *temp = CPU;
        int value = temp->value;
        CPU = CPU->next;
        delete temp;
        return value;
    }

    int dequeueExeTime()
    {
        if (ExeTime == nullptr)
        {
            cout << "Execution time queue is empty" << endl;
            return -1;
        }
        Node *temp = ExeTime;
        int value = temp->value;
        ExeTime = ExeTime->next;
        delete temp;
        return value;
    }

    int dequeueMemory()
    {
        if (Memory == nullptr)
        {
            cout << "Memory queue is empty" << endl;
            return -1;
        }
        Node *temp = Memory;
        int value = temp->value;
        Memory = Memory->next;
        delete temp;
        return value;
    }

    int dequeueStorage()
    {
        if (Storage == nullptr)
        {
            cout << "Storage queue is empty" << endl;
            return -1;
        }
        Node *temp = Storage;
        int value = temp->value;
        Storage = Storage->next;
        delete temp;
        return value;
    }
};

class PriorityQueue : public Task
{

public:
    Node *pq;

    PriorityQueue()
    {
        pq = nullptr;
    }

    void priority()
    {
        int count = 1;

        while (count <= 4)
        {
            int sum = dequeueCPU() + dequeueMemory() + dequeueStorage();
            InsertInSorted(pq, sum, count);
            count++;
        }
    }
};

class VM
{
public:
    int CPU;
    int Memory;
    int Storage;

    VM()
    {
        CPU = 60;
        Memory = 1024;
        Storage = 5;
    }
    bool canExecute(int task)
    {
        if (CPU + Memory + Storage >= task)
        {
            return true;
        }
        return false;
    }
};

class Execution : public PriorityQueue
{
    VM Machine[3];

public:
    void Assign()
    {
        Node *temp = pq;

        for (int i = 0; i < 3; i++)
        {
            if (Machine[i].canExecute(pq->value))
            {
                cout << "VM : " << i + 1 << " is executing Task with ID : " << temp->pos << endl;
            }
            else
            {
                cout << "Failed to Execute Task" << endl;
            }

            if (pq == nullptr)
            {
                cout << "No more tasks to Assign" << endl;
            }
            else
            {
                temp = temp->next;
            }
        }
    }
};

int main()
{

    int arr1[4] = {30, 20, 40, 25};
    int arr2[4] = {20, 15, 25, 18};
    int arr3[4] = {512, 256, 768, 384};
    int arr4[4] = {2, 1, 3, 2};

    Execution e;
    e.enqueueCPU(arr1, 4);
    e.enqueueExeTime(arr2, 4);
    e.enqueueMemory(arr3, 4);
    e.enqueueStorage(arr4, 4);

    e.priority();
    e.Assign();
}