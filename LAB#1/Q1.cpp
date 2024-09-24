#include<iostream>
using namespace std;

class BankAccount{
    private:
    double balance;

    public:
    BankAccount(){
        balance = 0.0;
        cout << "Default Constructor" << endl;
    }
    BankAccount( double val ){
        balance = val;
        cout << "Parameterized Constructor" << endl;
    }
    BankAccount( const BankAccount& other ){

        if( this != &other ){
            balance = other.balance;
        }    
        cout << "Copy Constructor Called" << endl;
    }

    void Deduct( double val ){
        if( balance - val < 0  || val <0 ){
            cout << "Not Enough Balance" << endl;
        }
        else{
            balance -= val;
            cout << "Deposited Successfully" << val << endl;
        }
    }

    void display(){
        cout << "Balance In Account : " << balance << endl;
    }    

};

int main(){

    BankAccount account1;
    account1.display();

    BankAccount account2(1000);
    account2.display();

    BankAccount account3 = account2;
    account3.Deduct(200);
    account3.display();

    account2.display();
}