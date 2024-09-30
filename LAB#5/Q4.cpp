#include <iostream>
using namespace std;

int recursiveArray123(int **arr, int size, int dim) {
    int sum = 0;

    if (dim <= 0) {
        return 0;  
    } 
    else {
        for (int j = 0; j < size; j++) {
            sum += arr[dim-1][j];
        }  
        sum += recursiveArray123(arr, size, dim - 1); 
    }
    return sum;
}

int main() {
    int n = 5; 
    int size = 3; 

    int *arr[5];

    for (int i = 0; i < n; i++) {
        arr[i] = new int[size]; 
        for (int j = 0; j < size; j++) {
            arr[i][j] = 1; 
        }
    }

    int sum = recursiveArray123(arr, size, n);
    cout << "Sum of all Elements in Jagged Array: " << sum << endl;

    for (int i = 0; i < n; i++) {
        delete[] arr[i]; 
    }

}
