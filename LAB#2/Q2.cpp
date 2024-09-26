#include<iostream>
#include "matrix_multiply.cpp"

using namespace N;
using namespace std;
int main(){

    int r = 3;
    int c = 3;

    int *arr1[r];
    int *arr2[r];
    int *res[r];

    for(int i=0; i<r; i++){
        arr1[i] = new int[c];
        arr2[i] = new int[c];
        res[i]  = new int[c];
    }

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){

            int val1,val2;
            cout << "Enter val for arr1 and arr2 : " << endl;
            cin >> val1 >> val2;

            arr1[i][j] = val1;
            arr2[i][j] = val2;
        }
    }
    
   Multiply m;
    m.multi(arr1, arr2, res, r, c);

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
     
     for(int i=0; i<r; i++){
        delete []arr1[i];
        delete []arr2[i];
        delete []res[i];
     }

    
}
