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

    bool isFull() {
        return ((back + 1) % n == front);
    }

    bool isEmpty() {
        return (front == -1);
    }

    void enqueue(int s)
    {
        if (isFull()) {
            cout << "\nQueue Full..";
            return;
        }

        if (isEmpty()) {
            front = back = 0;
        } else {
            back = (back + 1) % n;
        }
        arr[back] = s;
    }

    void dequeue()
    {
        if (isEmpty()) {
            cout << "\nQueue Empty.";
            return;
        }

        if (front == back) {
            // Only one element
            front = back = -1;
        } else {
            front = (front + 1) % n;
        }
    }

    int top()
    {
        if (isEmpty()) {
            cout << "\nQueue Empty.";
            return -1;
        }
        return arr[front];
    }

    void display()
    {
        if (isEmpty()) {
            cout << "\nQueue Empty.";
            return;
        }

        cout << "\nQueue: ";
        int i = front;
        while (true)
        {
            cout << arr[i] << " ";
            if (i == back) break;
            i = (i + 1) % n;
        }
        cout << endl;
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
    cout << "\nTop: " << s1.top() << endl;

    s1.enqueue(50);

    s1.dequeue();
    s1.enqueue(50);
    s1.display();
    cout << "\nTop: " << s1.top() << endl;

    s1.dequeue();
    s1.dequeue();
    s1.display();
    cout << "\nTop: " << s1.top() << endl;

    return 0;
}

