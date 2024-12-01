#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

class task {
    public:
    int id;
    int priority;
};

void max_heapify(task arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left].priority > arr[largest].priority) {
        largest = left;
    }

    if (right < n && arr[right].priority > arr[largest].priority) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        max_heapify(arr, n, largest);
    }
}

void Build_Max_Heap(task arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        max_heapify(arr, n, i);
    }
}

void Delete_Root(task arr[], int& n) {
    arr[0] = arr[n - 1];
    n--;
    max_heapify(arr, n, 0);
}

int main() {
    srand(time(0));
    int n = 10;
    

    task arr[10];
    for (int i = 0; i < n; i++) {
        arr[i].id = i + 1;
        arr[i].priority = rand() % 10 + 1;
    }

    Build_Max_Heap(arr, n);

    cout << "Tasks (by priority):" << endl;
    while (n > 0) {
        cout << "Task " << arr[0].id << " with priority " << arr[0].priority << endl;
        Delete_Root(arr, n);
    }
}
