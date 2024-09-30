#include <iostream>
using namespace std;

bool isValid(bool arr[4][4], int r, int c, int size)
{
    int x = r;
    int y = c;

    while (y >= 0)
    {
        if (arr[x][y] == true)
        {
            return false;
        }
        y--;
    }

    x = r;
    y = c;
    while (x >= 0 && y >= 0)
    {
        if (arr[x][y] == true)
        {
            return false;
        }
        x--;
        y--;
    }

    x = r;
    y = c;
    while (x < size && y >= 0)
    {
        if (arr[x][y] == true)
        {
            return false;
        }
        x++;
        y--;
    }

    return true;
}

void solve(bool arr[4][4], int col, int size, int &maxi, int curr)
{
    if (col == size)
    {
        maxi = max(maxi, curr);
        return;
    }

    for (int row = 0; row < size; row++)
    {
        if (isValid(arr, row, col, size))
        {
            arr[row][col] = true;
            solve(arr, col + 1, size, maxi, curr + 1);
            arr[row][col] = false;
        }
    }
}

int main()
{
    bool arr[4][4] = {{false}};
    int count = 0;

    solve(arr, 0, 4, count, 0);

    cout << "Max Num of Flags  Place in a 4x4 Grid: " << count << endl;

    return 0;
}
