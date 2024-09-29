#include <iostream>
using namespace std;

class Record
{
public:
	int month;
	int year;
	int day;

	void Setter(int d, int y, int dy)
	{
		month = d;
		year = y;
		day = dy;
	}
};

void print(Record obj[], int n)
{

	for (int i = 0; i < 5; i++)
	{
		cout << obj[i].month << "/" << obj[i].day << "/" << obj[i].year << endl;
	}
}

void SeLECtionSORT76(Record obj[], int n)
{
	int mini;

	for (int i = 0; i < n - 1; i++)
	{
		mini = i;

		for (int j = i + 1; j < n; j++)
		{
			if (obj[j].year < obj[mini].year)
			{
				mini = j;
			}
		}

		if (mini != i)
		{
			Record temp = obj[i];
			obj[i] = obj[mini];
			obj[mini] = temp;
		}
	}
}
int main()
{

	Record obj[5];
	int dt, yr, dy;

	for (int i = 0; i < 5; i++)
	{
		cout << "Enter date : ";
		cin >> dt;
		cout << "Enter year : ";
		cin >> yr;
		cout << "Enter day : ";
		cin >> dy;

		obj[i].Setter(dt, yr, dy);
	}

	SeLECtionSORT76(obj, 5);
	print(obj, 5);
}
