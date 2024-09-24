#include<iostream>
using namespace std;

class Exam{
    private:
    string std_name;
    int date;
    int score;

    public:
    void SetName( string name){
        std_name = name;
    }
    void SetDate( int date ){
        this->date = date;
    }
    void SetScore( int sc ){
        score = sc;
    }
    void display(){
        cout << "Student Name : " << std_name << endl;
        cout << "Date : " << date << endl;
        cout << "Score : " << score << endl;
    }
};

int main(){

    Exam obj1;
    obj1.SetDate(20);
    obj1.SetName("Abdullah");
    obj1.SetScore(95);
    obj1.display();

    Exam obj2 = obj1;
    obj2.display();

    cout << "On Omitting Implementation Default Copy Constructor is Used" << endl;
}