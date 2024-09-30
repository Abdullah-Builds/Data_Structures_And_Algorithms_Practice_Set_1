#include <iostream>
using namespace std;

bool Check(int arr[5][5], bool isVisited[5][5], int destination, int srcx, int srcy)
{

    if (srcx >= 0 && srcy >= 0 && srcx <= destination && srcy <= destination && isVisited[srcx][srcy] == 0 && arr[srcx][srcy] == 1)
    {
        return true;
    }
    return false;
}

void print( bool ans[5][5], int size){
    
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    cout << "***************************" << endl;
}

void solve(int arr[5][5], bool isVisited[5][5], bool ans[5][5], int destination, int srcx, int srcy)
{

    if ( srcx == destination  && srcy == destination  )
    {
        ans[srcx][srcy] = 1;
        print(ans,5);
        ans[srcx][srcy] = 0;
        return;
    }

    isVisited[srcx][srcy] = true;
    ans[srcx][srcy] = true;

    int newx = srcx - 1;
    int newy = srcy;

    if (Check(arr, isVisited, destination , newx, newy))
    {
        solve(arr, isVisited, ans, destination, newx, newy);
    }
    newx = srcx + 1;
    newy = srcy;

    if (Check(arr, isVisited, destination , newx, newy))
    {
        solve(arr, isVisited, ans, destination, newx, newy);
    }
    newx = srcx;
    newy = srcy + 1;

    if (Check(arr, isVisited, destination , newx, newy))
    {
        solve(arr, isVisited, ans, destination, newx, newy);
    }
    newx = srcx;
    newy = srcy - 1;

    if (Check(arr, isVisited, destination , newx, newy))
    {
        solve(arr, isVisited, ans, destination, newx, newy);
    }

    isVisited[srcx][srcy] = false;
    ans[srcx][srcy] = false;
}

int main()
{

    int arr[5][5] = { {1, 0, 1, 0, 1},
                      {1, 1, 1, 1, 1},
                      {0, 1, 0, 1, 1},
                      {1, 0, 0, 1, 1},
                      {1, 1, 1, 0, 1}};

    bool isVisited[5][5] = {{false}};
    bool ans[5][5]  = {{false}};
    int destination = 4;
    int srcx = 0;
    int srcy = 0;

    solve(arr,isVisited,ans,destination,srcx,srcy); 
     cout << "Total 4 paths are found";   
                 

    }
