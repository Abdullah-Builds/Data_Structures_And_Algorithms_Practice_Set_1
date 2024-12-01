#include <iostream>
using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}
void min_heapify(int *arr, int n, int i) {
    int index = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[index]) {
        index = left;
    }

    if (right < n && arr[right] < arr[index]) {
        index = right;
    }

    if (index != i) {
        swap(arr[i], arr[index]);
        min_heapify(arr, n, index);
    }
}

void Build_Min_heap(int *arr, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        min_heapify(arr, n, i);
    }
}

void max_heapify(int *arr, int n, int i) {
    int index = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[index]) {
        index = left;
    }

    if (right < n && arr[right] > arr[index]) {
        index = right;
    }

    if (index != i) {
        swap(arr[i], arr[index]);
        max_heapify(arr, n, index);
    }
}

void Build_Max_Heap(int *arr, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        max_heapify(arr, n, i);
    }
}

int main() {
    int arr1[] = {7, 1, 6, 2, 5, 9, 10, 2};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    Build_Min_heap(arr1, n1);
    cout << "Min Heap : ";
    for (int i = 0; i < n1; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;

    int arr2[] = {7, 1, 6, 2, 5, 9, 10, 2};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    Build_Max_Heap(arr2, n2);
    cout << "Max Heap : ";
    for (int i = 0; i < n2; i++) {
        cout << arr2[i] << " ";
    }

}
