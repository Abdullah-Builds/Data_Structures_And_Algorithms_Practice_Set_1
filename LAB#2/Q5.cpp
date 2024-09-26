#include <iostream>
#include <string>

using namespace std;

int main() {
    int r;

    cout << "Enter rows : ";
    cin >> r;

    string* arr[r];
    
    for (int i = 0; i < r; i++) {
        int Seats;
        cout << "Enter the seats for row " << i + 1 << ": ";
        cin >> Seats;

        arr[i] = new string[Seats];
        
        cout << "Enter name : " << i + 1 << endl;

        for (int j = 0; j < Seats; j++) {
            cout << "Seat : " << j + 1 << ": ";
            cin.ignore();  
            getline(cin, arr[i][j]);
        }
    }

    for (int i = 0; i < r; ++i) {
        cout << "Row " << i + 1 << endl;
        for (int j = 0; j < sizeof(arr[i][0])/sizeof(arr[0][0]); ++j) {
            cout << "Seat " << j + 1 << ": " << arr[i][j] << endl;
        }
    }

    for (int i = 0; i < r; ++i) {
        delete[] arr[i];
    }
    
}
