#include <iostream>
using namespace std;

// My Roll Number is 23k-0607
void SELectionSort(int *arr, int n)
{
    int mini;

    for (int i = 0; i < n - 1; i++)
    {
        mini = i;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[mini])
            {
                mini = j;
            }
        }

        if (mini != i)
        {
            int temp = arr[i];
            arr[i] = arr[mini];
            arr[mini] = temp;
        }
    }
}
void print(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

bool Binary(int *arr, int size, int Roll)
{
    int start = 0;
    int end = size - 1;

    int target = Roll % 100;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        int val = arr[mid];
        if (val == target)
        {
            return true;
        }
        else if (val < target)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return false;
}

int main()
{
    int arr[11] = {12, 123, 312, 31, 32, 323, 3, 2356, 76, 7676};

    SELectionSort(arr, 10);
    print(arr, 10);

    if (Binary(arr, 10, 0607))
    {
        cout << "Element present that matched with last 2 digits of roll number" << endl;
    }
    else
    {
        cout << "Not Found" << endl;

        arr[10] = 07;
        SELectionSort(arr, 11);

        cout << "Updated array: ";
        print(arr, 11);
    }

}
