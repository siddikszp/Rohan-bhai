#include <iostream>
using namespace std;

class stack {
public:
    char* arr;
    int n;
    int top;

    stack(int size) {
        n = size;
        arr = new char[n];
        top = -1;
    }

    void push(char x) {
        if (top == n - 1) {
            cout << "\nStack full";
            return;
        }
        top++;
        arr[top] = x;
    }

    void pop() {
        if (top == -1) {
            cout << "\nStack empty";
            return;
        }
        top--;
    }

    char topElement() {
        if (top == -1) {
            cout << "\nStack empty. No Top";
            return '\0';
        }
        return arr[top];
    }

    void display() {
        cout << "\nStack: ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i];
        }
        cout << endl;
    }
};

int main() {
    string input;
    cout << "Main Stack: ";
    getline(cin, input);

    stack s(input.length());

    for (char c : input) {
        s.push(c);
    }

    cout << "Reversed Stack: ";

    while (s.top != -1) {
        cout << s.topElement();
        s.pop();
    }
    cout << endl;

    return 0;
}

