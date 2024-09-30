#include<iostream>
using namespace std;
class stack{
    
    public : 
    int top;
    int size;
    char *arr;

    stack(int s){
        size = s;
        top = -1;
        arr = new char [size];
    }
    stack(){
        size = -1;
        top = -1;
        arr = nullptr;
    }

    void push(char val){

        if( size - top > 1){
            top++;
            arr[top] = val;
        }
        else {
            cout << "Stack Overflow " << endl;
        }
    }

    void pop(){

        if( top != -1 ){
           top--;
        }
        else{

            cout << "Stack Underflow " << endl;
        }
    }

    char peek(){
        if( top !=- 1 ){
            return arr[top];
        }
        else{
            cout << "Stack is Empty " << endl;
            return -1;
        }
    }

    bool empty(){

        if ( top == -1) return false;
        return true;
    }
    ~stack(){
        delete []arr;
    }
};

bool isPalindrome(stack &s){

    char *temp = new char [s.size];
    int index =  0;

    while( !s.empty() ){
        temp[index++] = s.peek();
        s.pop();
    }

    int start = 0;
    int end = s.size;

    while( start < end){
        if( temp[start] != temp[end] ){
            delete []temp;
            return false;
        }
        start++;
        end--;
    }
    delete []temp;
    return true;
}

int main(){
    
    string word = "BORROWROB";

    stack s(word.size());
    s.push('B');
    s.push('O');
    s.push('R');
    s.push('R');
    s.push('O');
    s.push('W');
    s.push('R');
    s.push('O');
    s.push('B');
    
    bool found = isPalindrome(s);

    if( found ) {
        cout << "It is a Palindrom : " << word << endl;
    }
    else{
        cout << "Not a Palindrome : " << word << endl;
    }

}