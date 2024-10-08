#include <iostream>
using namespace std;

class Queue {
public:
    int front;
    int rear;
    int *arr;
    int size;

    Queue(int s) {
        front = 0;
        rear = 0;
        size = s;
        arr = new int[size];
    }

    void enqueue(int val) {
        if (rear < size) {
            arr[rear++] = val;
        } else {
            cout << "Queue Overflow" << endl;
        }
    }

    void dequeue() {
        if (front < rear) {
            front++;
        } else {
            cout << "Queue is Empty" << endl;
        }
    }

    bool empty() {
        return front == rear;
    }

    int Front() {
        if (front < rear) {
            return arr[front];
        } else {
            cout << "Queue is Empty" << endl;
            return -1;
        }
    }
};

int main() {
    int arr[7] = {13, 7, 4, 1, 6, 8, 10};
    Queue q(7);

    for (int i = 0; i < 7; i++) {
        q.enqueue(arr[i]);
    }

    int i = 1;
    while (!q.empty()) {
        cout << "CheckOut " << i << " : " << q.Front() << endl;
        q.dequeue();
        i++;
    }

    delete[] q.arr;
    return 0;
}
