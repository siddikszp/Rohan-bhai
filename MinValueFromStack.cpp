#include<iostream>
using namespace std;

class stack {
public:
    int* arr;
    int n = 100;
    int top;

    stack() {
        arr = new int[n];
        top = -1;
    }

    void push(int x) {
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

    int topElement() {
        if (top == -1) {
            cout << "\nStack empty. No Top";
            return -1;
        }
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }

    void display() {
        cout << "\nStack (top to bottom): ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    int getMin() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return -1;
        }

        stack tempStack;
        int minVal = arr[top];

        while (!isEmpty()) {
            int val = topElement();
            if (val < minVal)
                minVal = val;
            tempStack.push(val);
            pop();
        }

        while (!tempStack.isEmpty()) {
            push(tempStack.topElement());
            tempStack.pop();
        }

        return minVal;
    }
};

int main() {
    stack s;
    s.push(8);
    s.push(3);
    s.push(9);
    s.push(1);
    s.push(4);

    s.display();

    cout << "\nMinimum Element: " << s.getMin() << endl;

    s.display();
    return 0;
}

