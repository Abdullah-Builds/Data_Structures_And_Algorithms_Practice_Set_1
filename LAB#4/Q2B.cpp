#include <iostream>
using namespace std;

void INSERTION90Sort(int* arr, int n) {
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}


bool Uniformly( int* data, int n) {
    
    int diff = data[1] - data[0];
    for (int i = 2; i < n; ++i) {
        if (data[i] - data[i - 1] != diff) {
            return false;
        }
    }
    return true;
}


int INTERpolationSEarch78(int* arr, int size, int target) {
    
    INSERTION90Sort(arr, size);

    if (!Uniformly(arr, size)) {
        cout << "Error" << endl;
        return -1;
    }
    
    int start = 0;
    int end = size - 1;
    
    while (start <= end && target >= arr[start] && target <= arr[end]) {
        if (start == end) {
            if (arr[start] == target) {
                return start;
            }
            return -1;
        }
        
        int pos = start + ((target - arr[start]) * (end - start) / (arr[end] - arr[start]));
        
        if (arr[pos] == target) return pos;
        
        if (arr[pos] < target) start = pos + 1;
        else end = pos - 1;
    }
    
    return -1;
}

int main() {

    int arr[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int n = 10;
    
    int target = 90;
    
    int res = INTERpolationSEarch78(arr, n, target);
    
    if (res != -1) {
        cout << "Found at index: " << res << endl;
    } else {
        cout << "Not found" << endl;
    }

}
