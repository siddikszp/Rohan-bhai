#include<iostream>
using namespace std;

class stack{

 public:

     int *arr;
     int top;
     int n = 4;

     stack()
     {
         arr = new int [n];
         top = -1;
     }
     void push(int x){

         if (top == n-1){
         cout<<"\nStack is Full"<<endl;
         return;
     }
     top++;
     arr[top]=x;
     }

     void pop(){

         if (top == -1){
         cout<<"\nStack is empty."<<endl;
         return;
      }
     top--;
     }
    int topElement(){


         if (top == -1){
         cout<<"\nStack is empty."<<endl;
         return -1;
      }

    return arr[top];
    }
    void display(){

    cout<<"\nStack: ";

    for(int i = top; i>=0; i--)
    {
        cout<<arr[i]<<" ";
    }

 }

};


int main(){

 stack st;

 st.push(10);
 st.push(20);
 st.push(30);
 st.push(40);
  st.pop();
  st.display();

 cout<<"\nTop: "<<st.topElement() <<endl;


}

