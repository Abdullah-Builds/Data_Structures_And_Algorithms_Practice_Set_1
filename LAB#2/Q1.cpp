#include <iostream>
using namespace std;

int main()
{

    int *JaggedArray[5];

    for (int i = 0; i < 5; i++)
    {
        JaggedArray[i] = new int[5] {1,2,3,4,5};
    }

    for (int i = 0; i < 5; i++)
    {

        int *Resize = new int[10];

        for (int j = 0; j < 5; j++)
        {
            Resize[j] = JaggedArray[i][j];
        }

        for (int k = 5; k < 10; k++)
        {
            // Hardcode values for ease we can take input
            Resize[k] = k + 1;
        }

        delete[] JaggedArray[i];
        JaggedArray[i] = Resize;
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << JaggedArray[i][j] << " ";
        }
        cout << endl;
    }

     for (int i = 0; i < 5; i++)
    {
        delete[] JaggedArray[i];
    }
}
