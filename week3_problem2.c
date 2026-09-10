#include <iostream>
#include <stack>
#include <algorithm>
#include <cctype>
using namespace std;

// Function to return precedence
int precedence(char op) {
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

// Convert Infix to Prefix
string infixToPrefix(string infix) {
    reverse(infix.begin(), infix.end());

    // Swap brackets
    for (int i = 0; i < infix.length(); i++) {
        if (infix[i] == '(')
            infix[i] = ')';
        else if (infix[i] == ')')
            infix[i] = '(';
    }

    stack<char> st;
    string postfix = "";

    for (char ch : infix) {

        // Operand
        if (isalnum(ch))
            postfix += ch;

        // Opening bracket
        else if (ch == '(')
            st.push(ch);

        // Closing bracket
        else if (ch == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            if (!st.empty())
                st.pop();
        }

        // Operator
        else {
            while (!st.empty() &&
                   precedence(st.top()) > precedence(ch)) {
                postfix += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }

    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }

    // Reverse postfix to get prefix
    reverse(postfix.begin(), postfix.end());

    return postfix;
}

int main() {
    string infix;

    cout << "Enter Infix Expression: ";
    cin >> infix;

    cout << "Prefix Expression: "
         << infixToPrefix(infix);

    return 0;
}
