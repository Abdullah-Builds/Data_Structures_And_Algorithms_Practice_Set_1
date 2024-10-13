#include <iostream>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b; 
    b = temp; 
}
int partition_ascending(int* arr, int s, int e) {
    int mid = s + (e - s) / 2;
    int pivot = arr[mid];
    swap(arr[mid], arr[e]);
    int i = s - 1;

    for (int j = s; j < e; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[e]);
    return (i + 1);
}

void Quick_Sort_Ascending(int* arr, int s, int e) {
    if (s >= e) {
        return;
    }
    int p = partition_ascending(arr, s, e);
    Quick_Sort_Ascending(arr, s, p - 1);
    Quick_Sort_Ascending(arr, p + 1, e);
}

int partition_descending(int* arr, int s, int e) {
    int mid = s + (e - s) / 2;
    int pivot = arr[mid];
    swap(arr[mid], arr[e]);
    int i = s - 1;

    for (int j = s; j < e; j++) {
        if (arr[j] >= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[e]);
    return (i + 1);
}

void Quick_Sort_Descending(int* arr, int s, int e) {
    if (s >= e) {
        return;
    }
    int p = partition_descending(arr, s, e);
    Quick_Sort_Descending(arr, s, p - 1);
    Quick_Sort_Descending(arr, p + 1, e);
}

int* Sort_Array_In_Ascending(int* arr, int n) {
    int* arr1 = new int[n];
    for (int i = 0; i < n; i++) {
        arr1[i] = arr[i];
    }
    Quick_Sort_Ascending(arr1, 0, n - 1);
    return arr1;
}

int* Sort_Array_In_Descending(int* arr, int n) {
    int* arr1 = new int[n];
    for (int i = 0; i < n; i++) {
        arr1[i] = arr[i];
    }
    Quick_Sort_Descending(arr1, 0, n - 1);
    return arr1;
}

int main() {
    int arr[10] = {9, 2, 3, 5, 7, 1, 8, 0, 6, 4};
    int n = 10;

    int* Ascending123 = Sort_Array_In_Ascending(arr, n);
    int* Descending123 = Sort_Array_In_Descending(arr, n);

    cout << "Ascending: ";
    for (int i = 0; i < n; i++) {
        cout << Ascending123[i] << " ";
    }

    cout << endl << "Descending: ";
    for (int i = 0; i < n; i++) {
        cout << Descending123[i] << " ";
    }
    cout << endl;

    delete[] Ascending123;
    delete[] Descending123;

}
