#include<iostream>
using namespace std;

class queue
{

public:

    int* arr;
    int n = 4;
    int front;
    int back;

    queue()
    {
        arr = new int[n];
        front = -1;
        back = -1;
    }
    void enqueue(int s)
    {
        if(back == n-1)
        {
            cout << "\Queue Full..";
            return;
        }
        back++;
        arr[back] = s;
        if(front == -1)
        {
            front++;
        }
    }
    void dequeue()
    {
        if(front == -1 || front > back)
        {
            cout << "\Queue Empty.";
            return;
        }
        front++;
    }
    int top()
    {
        if(front == -1 || front > back)
        {
            cout << "\Queue Empty.";
            return -1;
        }
        return arr[front];
    }
    void display()
    {
        if(front == -1 || front > back)
        {
            cout << "\Queue Empty.";
            return;
        }
        cout << "\nQueue: ";
        for (int i = front; i <= back; i++)
        {
            cout << arr[i] << " ";
        }
    }
};

int main()
{
    queue s1;
    s1.enqueue(10);
    s1.enqueue(20);
    s1.enqueue(30);
    s1.enqueue(40);
    s1.display();
    cout << "\nTop: " <<s1.top() <<endl;

    s1.enqueue(50);

    s1.dequeue();
    s1.display();
    cout << "\nTop: " <<s1.top() <<endl;

    s1.dequeue();
    s1.dequeue();
    s1.display();
    cout << "\nTop: " <<s1.top() <<endl;
}

