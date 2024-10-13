#include <iostream>
using namespace std;

void countingSort(int* arr, int n, int exp, bool ascending) {
    int output[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    if (ascending) {
        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }
    }
	else {
        for (int i = 8; i >= 0; i--) {
            count[i] += count[i + 1];
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        int index = (arr[i] / exp) % 10;
        output[count[index] - 1] = arr[i];
        count[index]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

int* radixSort123(int* arr, int n, bool ascending) {
    int* sorted = new int[n];
    for (int i = 0; i < n; i++) {
        sorted[i] = arr[i];
    }

    int maxi = sorted[0];
    for (int i = 1; i < n; i++) {
        if (sorted[i] > maxi) {
            maxi = sorted[i];
        }
    }

    for (int exp = 1; maxi / exp > 0; exp *= 10) {
        countingSort(sorted, n, exp, ascending);
    }

    return sorted;
}

int main() {
    int arr[10] = {9, 2, 3, 5, 7, 1, 8, 0, 6, 4};
    int n = 10;

    int* ascending = radixSort123(arr, n, true);
    int* descending = radixSort123(arr, n, false);

    cout << "Ascending : ";
    for (int i = 0; i < n; i++) {
        cout << ascending[i] << " ";
    }
    cout << endl;

    cout << "Descending : ";
    for (int i = 0; i < n; i++) {
        cout << descending[i] << " ";
    }
    cout << endl;

    delete[] ascending;
    delete[] descending;

}