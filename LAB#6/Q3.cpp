#include <iostream>
#include <string>
#include <cctype>
#include <cmath>

using namespace std;

struct Node {
    float val;
    Node* next;
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    void push(float value) {
        Node* newNode = new Node();
        newNode->val = value;
        newNode->next = top;
        top = newNode;
    }

    float pop() {
        if (top == nullptr) {
            return -1;
        }
        Node* temp = top;
        top = top->next;
        float popp = temp->val;
        delete temp;
        return popp;
    }

    float peek() {
        if (top == nullptr) {
            return -1;
        }
        return top->val;
    }

    bool isEmpty() {
        return top == nullptr;
    }
};

float perform(float x, float y, char ch) {
    switch (ch) {
        case '*': return x * y;
        case '/': return x / y;
        case '^': return pow(x, y);
        case '+': return x + y;
        case '-': return x - y;
        default: return 0;
    }
}

bool isOperator908(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

int prece(char c) {
    if (c == '^') return 3;
    else if (c == '*' || c == '/') return 2;
    else if (c == '+' || c == '-') return 1;
    else return -1;
}

string Logic(string check) {
    Stack st;
    string postfix;
    int i = 0;

    while (i < check.length()) {
        char c = check[i];

        if (isdigit(c) || c == '.') {
            while (i < check.length() && (isdigit(check[i]) || check[i] == '.')) {
                postfix += check[i];
                i++;
            }
            postfix += ' ';
            continue;
        } 

        if (c == '(') {
            if (i > 0 && (isdigit(check[i - 1]) || check[i - 1] == ')')) {
                postfix += '*';
                postfix += ' ';
            }
            st.push(c);
        } 
        else if (c == ')') {
            while (!st.isEmpty() && st.peek() != '(') {
                postfix += st.pop();
                postfix += ' ';
            }
            st.pop();
        } 
        else if (isOperator908(c)) {
            while (!st.isEmpty() && prece(c) <= prece(st.peek())) {
                postfix += st.pop();
                postfix += ' ';
            }
            st.push(c);
        }

        i++;
    }

    while (!st.isEmpty()) {
        postfix += st.pop();
        postfix += ' ';
    }

    return postfix;
}

float solve(string postfix) {
    Stack st;
    int i = 0;

    while (i < postfix.length()) {
        char c = postfix[i];

        if (isdigit(c) || c == '.') {
            string num;
            while (i < postfix.length() && (isdigit(postfix[i]) || postfix[i] == '.')) {
                num += postfix[i];
                i++;
            }
            st.push(stof(num));  // string  To float
        } 
        else if (isOperator908(c)) {
            float b = st.pop();
            float a = st.pop();
            float result = perform(a, b, c);
            st.push(result);
        }
        i++;
    }

    return st.pop();
}

int main() {
    string infix = "12+13-5*(0.5+0.5)+1";

    string postfix = Logic(infix);
    cout << "Postfix expression: " << postfix << endl;

    float res = solve(postfix);
    cout << "Result: " << res << endl;

}
