#include <iostream>
#include <string>
#include <cmath>
using namespace std;

template <typename T>
class ListNode {
public:
    T value; 
    ListNode *nextNode;
    ListNode(T v) {
        value = v;
        nextNode = NULL;
    }
};

template <typename T>
class CustomStack {
public:
    ListNode<T> *topNode;
    CustomStack() {
        topNode = NULL;
    }

    void push(T value) {
        ListNode<T> *newNode = new ListNode<T>(value);
        newNode->nextNode = topNode;
        topNode = newNode;
    }

    T pop() {
        if (!isEmpty()) {
            T returnValue = topNode->value;
            ListNode<T> *tempNode = topNode;
            topNode = topNode->nextNode;
            delete tempNode;
            return returnValue;
        }
        return T(); 
    }

    bool isEmpty() {
        return topNode == NULL;
    }

    T peek() {
        if (topNode == NULL)
            return T(); 
        return topNode->value;
    }
};

int operatorPrecedence009(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
        return 3;
    return 0;
}

bool isArithmeticOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

string convertInfixToPostfix(const string &infix) {
    CustomStack<char> operatorStack;  
    string post;
    for (int i = 0; i < infix.length(); i++) {
        char currentChar = infix[i];
        if (isdigit(currentChar) || currentChar == '.') {
            post += currentChar;
        } else if (currentChar == '(') {
            operatorStack.push(currentChar);
            post += ' ';
        } else if (currentChar == ')') {
            post += ' ';
            while (!operatorStack.isEmpty() && operatorStack.peek() != '(') {
                post += operatorStack.pop();
            }
            operatorStack.pop(); 
        } else if (isArithmeticOperator(currentChar)) {
            post += ' ';
            while (!operatorStack.isEmpty() && operatorPrecedence009(operatorStack.peek()) >= operatorPrecedence009(currentChar)) {
                post += operatorStack.pop();
            }
            operatorStack.push(currentChar);
        }
    }
    while (!operatorStack.isEmpty()) {
        post += ' ';
        post += operatorStack.pop();
    }
    return post;
}

double solve(string &post) {
    CustomStack<double> solve908;  
    string tempp = "";
    for (int i = 0; i < post.length(); i++) {
        char currentChar = post[i];

        if (isdigit(currentChar) || currentChar == '.') {
            tempp += currentChar;
        } else if (currentChar == ' ' && !tempp.empty()) {
            solve908.push(stod(tempp));
            tempp = "";
        } else if (isArithmeticOperator(currentChar)) {
            double operand2 = solve908.pop();
            double operand1 = solve908.pop();
            switch (currentChar) {
                case '+':
                    solve908.push(operand1 + operand2);
                    break;
                case '-':
                    solve908.push(operand1 - operand2);
                    break;
                case '*':
                    solve908.push(operand1 * operand2);
                    break;
                case '/':
                    solve908.push(operand1 / operand2);
                    break;
                case '^':
                    solve908.push(pow(operand1, operand2));
                    break;
            }
        }
    }
    return solve908.pop();
}

void reverse(string &s) {
    int start = 0;
    int end = s.length() - 1;

    while (start < end) {
        char temp = s[start];
        s[start] = s[end];
        s[end] = temp;
        start++;
        end--;
    }
}

int main()
{
    string infix123 = "12+13-5*(0.5+0.5)+1";
    string temp = "";

    for(int i=0; i< infix123.length(); i++){
        temp += infix123[i];
        temp += "";
    }

    string postfix44 = convertInfixToPostfix(infix123);
    cout << "Postfix : " << postfix44 << endl;

    double resultValue = solve(postfix44);
    cout << "Result: " << resultValue << endl;

    CustomStack <string>displayStack;

    for (int i = temp.length()-1; i >=0 ;)
    {
        string word = "";
        while (i < temp.length() && temp[i] != ' ' )
        {
            word += temp[i];
            i--;
        }
        if (!word.empty())
        {
            reverse(word);
            displayStack.push(word);
        }
        if (i < temp.length())
            i--; 
    }

    displayStack.push("="); 
    displayStack.push(to_string(resultValue));
    cout << "Expression and Result: ";
    while (!displayStack.isEmpty())
    {
        cout << displayStack.pop() << " ";
    }
    cout << endl;

}