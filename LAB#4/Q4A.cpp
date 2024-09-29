#include <iostream>
using namespace std;

// I use n + 3 here
void SHELL_Sort123(int *arr, int n)
{

    for (int gap = n + 3; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
            {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

void print(int *arr, int n)
{

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[10] = {60, 88, 65, 98, 123, 200, 55, 66, 100, 55};
    int n = 10;

    cout << " Before sorting: ";
    print(arr, n);

    SHELL_Sort123(arr, n);

    cout << "After sorting: ";
    print(arr, n);
}
