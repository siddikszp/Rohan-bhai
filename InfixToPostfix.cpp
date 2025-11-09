#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

int precedence(char op)
{
    if(op == '^')
    {
        return 3;
    }

    if(op == '*' || op == '/')
      {
        return 2;
      }
    if(op == '+' || op == '-')
    {
        return 1;
    }

    return -1;
}

string infixToPostfix(string infix)
{
    stack <char>st;
    string result;

    for(char c : infix)
    {
        if(isalnum(c))
        {
            result += c;  // Operand goes directly to result
        }
        else if(c == '(')
        {
            st.push(c);  // Push '(' on stack
        }
        else if(c == ')')
        {
            // Pop until '(' is found
            while(!st.empty() && st.top() != '(')
            {
                result += st.top();
                st.pop();
            }
            if(!st.empty()) st.pop();  // Remove '('
        }
        else
        {
            // Operator encountered
            // Pop operators from stack with higher or equal precedence
            while(!st.empty() && precedence(st.top()) >= precedence(c))
            {
                // For '^', which is right-associative, don't pop if same precedence
                if(c == '^' && st.top() == '^')
                    break;
                result += st.top();
                st.pop();
            }
            st.push(c);  // Push current operator
        }
    }

    // Pop all remaining operators
    while(!st.empty())
    {
        result += st.top();
        st.pop();
    }

    return result;
}

int main()
{
    string infix;
    cout << "Infix Expression: ";
    getline(cin, infix);

    string postfix = infixToPostfix(infix);
    cout << "Postfix Expression: " << postfix << endl;
}

