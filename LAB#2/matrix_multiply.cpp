#include "matrix_multiply.h"
#include<iostream>

using namespace std;
using namespace N;

    void Multiply::multi(int** arr1, int** arr2, int** res, int r, int c) {
    
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                res[i][j] = 0;
                for (int k = 0; k < c; ++k) {
                    res[i][j] += arr1[i][k] * arr2[k][j];
                }
            }
        }
    }

