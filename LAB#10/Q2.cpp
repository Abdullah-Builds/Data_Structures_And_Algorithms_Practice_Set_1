#include <iostream>
using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}
void min_heapify(int arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest]) {
        smallest = left;
    }

    if (right < n && arr[right] < arr[smallest]) {
        smallest = right;
    }

    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        min_heapify(arr, n, smallest);
    }
}

void Build_Min_Heap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        min_heapify(arr, n, i);
    }
}

void max_heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        max_heapify(arr, n, largest);
    }
}

void Build_Max_Heap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        max_heapify(arr, n, i);
    }
}

void Delete_Root(int arr[], int& n) {
    arr[0] = arr[n - 1];
    n--;
}

void HeapSort(int arr[], int n) {
    Build_Max_Heap(arr, n);
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        n--;
        max_heapify(arr, n, 0);
    }
}
void print(int *arr, int n){
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {35, 33, 42, 10, 14, 19, 27, 44, 26, 31};
    int n = sizeof(arr) / sizeof(arr[0]);

    Build_Min_Heap(arr, n);
    cout << "Build Min Heap : ";
    print(arr,n);

    Delete_Root(arr, n);
    

    Build_Max_Heap(arr, n);
    cout << "Build Max Heap : : " ;
    print(arr,n);
    
    HeapSort(arr, n);
    cout << "Heap Sort : ";
    print(arr,n);

}
