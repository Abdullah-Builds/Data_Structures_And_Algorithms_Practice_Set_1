#include <iostream>
using namespace std;

void COMB_SOrt90(float *arr, int n)
{
    int gap = n;
    float shrink = 0.8; // i use shrink 0.8
    bool swapped = true;

    while (gap > 1 || swapped)
    {
        if (gap > 1)
        {
            gap = int(gap * shrink);
        }
        else
        {
            gap = 1;
        }

        swapped = false;

        for (int i = 0; i + gap < n; i++)
        {
            if (arr[i] > arr[i + gap])
            {
                float temp = arr[i];
                arr[i] = arr[i + gap];
                arr[i + gap] = temp;
                swapped = true;
            }
        }
    }
}

void print(float *arr, int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    float arr[10] = {25.9923, 13.7589, 35.456, 442.9, 5.5, 2.49, 24.55, 789.3, 79.49, 1.93};
    int n = 10;

    cout << "Before sorting: ";
    print(arr, n);

    COMB_SOrt90(arr, n);

    cout << "After sorting: ";
    print(arr, n);
}
