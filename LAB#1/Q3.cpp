#include<bits/stdc++.h>
using namespace std;

class Document{
    private:
    char* text;

    public:
    Document(){
        cout << "Default Constructor" << endl;
    }

    Document( const char* data ){
        text = new char [strlen(data)+1];
        strcpy( text,data );
        cout << "Parameterized Constructor" << endl;
    }

    void Change( const char* data ){
        delete[] text;
        strcpy( text,data );
    }

    ~Document(){
        cout << "Destructor called" << endl;
        delete[] text;
    }

    Document( const Document& other ){
        if( this != &other){
              text = new char [strlen( other.text )+1];
              strcpy( text,other.text);
        }
        cout << "Copy Constructor" << endl;
    }

    Document& operator = ( const Document& other ){
        if( this != &other){
            delete[] text;
            text = new char [strlen( other.text )+1];
            strcpy( text,other.text);
        }
        cout << "Copy Assignment Operator Constructor" << endl;
        return *this;
    } 

    void display(){
        cout << text << endl;
    }
};

int main(){
    
    Document obj1( "I am doing DS Lab Tasks" );

    Document obj2 = obj1;
    Document obj3;
    obj3 = obj1;

    obj1.Change("I have Completed Lab Tasks");
    
    obj1.display();
    obj2.display();
    obj3.display();

}