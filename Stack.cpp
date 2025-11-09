#include<iostream>
using namespace std;

class  stack
{
public:

    int* arr;
    int n = 4;
    int top;

    stack ()
    {
        arr = new int[n];
        top=-1;
    }
    void push(int x)
    {
        if(top == n-1)
        {
            cout << "\nStack full";
            return;
        }
        top++;
        arr[top] = x;
    }
    void pop()
    {
        if(top==-1)
        {
            cout << "\nStack empty";
            return;
        }
        top--;
    }
    int topElement ()
    {
        if(top==-1)
        {
            cout << "\nStack empty. No Top";
            return -1;
        }
        return arr[top];
    }
    void display()
    {
        cout << "\nStack: ";
        for(int i = top; i >= 0 ; i--)
        {
            cout << arr[i] << " ";
        }
    }
};



int main ()
{
    stack s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.display();
    cout << "\nTop: " <<s1.topElement() <<endl;

    s1.push(50);

    s1.pop();
    s1.display();
    cout << "\nTop: " <<s1.topElement() <<endl;

}

