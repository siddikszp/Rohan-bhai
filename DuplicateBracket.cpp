#include <iostream>
#include <stack>
using namespace std;

bool hasDuplicateBrackets(string expr) {
    stack<char> st;

    for (char ch : expr) {
        if (ch == ')') {
            if (st.empty()) return false;

            bool isDuplicate = true;

            while (!st.empty() && st.top() != '(') {
                char top = st.top();
                st.pop();
                if (top != ' ' && top != '+' && top != '-' && top != '*' && top != '/') {
                    isDuplicate = false;
                }
            }

            if (!st.empty()) st.pop();

            if (isDuplicate) return true;
        } else {
            st.push(ch);
        }
    }

    return false;
}

int main() {
    string expr;
    cout << "Enter expression: ";
    getline(cin, expr);

    if (hasDuplicateBrackets(expr)) {
        cout << "Duplicate brackets found" << endl;
    } else {
        cout << "No Duplicate brackets" << endl;
    }

    return 0;
}

