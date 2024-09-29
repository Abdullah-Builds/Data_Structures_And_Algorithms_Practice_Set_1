#include <iostream>
using namespace std;

class Office
{
public:
    int key;
    string designation;

    void Setter(int k, string des)
    {
        key = k;
        designation = des;
    }
};

void print(Office obj[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << obj[i].designation << endl;
    }
}

void InsERTIONSort(Office obj[], int n)
{
    for (int i = 1; i < n; i++)
    {
        Office key = obj[i];
        int j = i - 1;

        while (j >= 0 && obj[j].key > key.key)
        {
            obj[j + 1] = obj[j];
            j--;
        }

        obj[j + 1] = key;
    }
}

int main()
{
    Office obj[8];
    string pos[8] = {"Employee", "CFO", "Manager", "Employee", "Vice_President", "CTO", "Manager", "CEO"};
    int KEY[8] = {6, 3, 5, 6, 4, 2, 5, 1};

    for (int i = 0; i < 8; i++)
    {
        obj[i].Setter(KEY[i], pos[i]);
    }

    InsERTIONSort(obj, 8);
    print(obj, 8);

}