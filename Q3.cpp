#include <iostream>
using namespace std;

int main()
{
    
    bool arr[5][5] = {
        {false, true, false, true, true},
        {true, false, true, false, true},
        {false, true, false, false, false},
        {true, false, false, false, true},
        {true, true, false, true, false}};


    for (int z = 0; z < 5; z++)
    {
        for (int p = z + 1; p < 5; p++)
        {
            for (int h = 0; h < 5; h++)
            {
                if (arr[z][h] && arr[p][h])
                {
                    cout << z << " and " << p << " are friends(knows)  : " << h << endl;
                }
            }
        }
    }
}
