#include<iostream>
#include<stack>
#include<string>
#include<algorithm>

using namespace std;

int precedence(char op)

{

  if (op == '^')
  {
      return 3;
  }

  if (op == '*' || '/')
  {
    return 2;
  }

   if (op == '+' || '-')
  {
    return 1;
  }

  return -1;

}

string InfixToPostfix (string infix)










}



int main(){

}
