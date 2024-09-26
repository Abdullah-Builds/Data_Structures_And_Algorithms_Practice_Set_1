#include <iostream>
using namespace std;

int main()
{
    double *Store_Data[4];
    string course[4] = {"SE", "AI", "CS", "DS"};

    Store_Data[0] = new double[3];
    Store_Data[1] = new double[4];
    Store_Data[2] = new double[2];
    Store_Data[3] = new double[1];

    cout << "Enter SE Courses GPA : " << endl;
    for (int i = 0; i < 3; i++)
    {
        double val;
        cin >> val;
        Store_Data[0][i] = val;
    }

    cout << "Enter AI Courses GPA : " << endl;
    for (int i = 0; i < 4; i++)
    {
        double val;
        cin >> val;
        Store_Data[1][i] = val;
    }

    cout << "Enter CS Courses GPA : " << endl;
    for (int i = 0; i < 2; i++)
    {
        double val;
        cin >> val;
        Store_Data[2][i] = val;
    }

    cout << "Enter DS Courses GPA : " << endl;
    double val;
    cin >> val;
    Store_Data[3][0] = val;

    for (int i = 0; i < 4; i++)
    {
        double score = 0.0;
        int NumCourses;

        if (i == 0)    NumCourses = 3; 
        else if (i == 1) NumCourses = 4;
        else if (i == 2) NumCourses = 2; 
        else if (i == 3) NumCourses = 1; 

        for (int j = 0; j < NumCourses; j++)
        {
            score += Store_Data[i][j];
        }
        cout << course[i] << " GPA : " << score / NumCourses << endl;
    }

    for (int i = 0; i < 4; i++)
    {
        delete[] Store_Data[i];
    }

    return 0;
}
