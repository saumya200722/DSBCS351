#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

// Function to evaluate postfix expression
int evaluatePostfix(string postfix) {
    stack<int> st;

    for (char ch : postfix) {

        // If operand, push onto stack
        if (isdigit(ch)) {
            st.push(ch - '0');
        }

        // If operator
        else {
            int val2 = st.top();
            st.pop();

            int val1 = st.top();
            st.pop();

            switch (ch) {
                case '+':
                    st.push(val1 + val2);
                    break;
                case '-':
                    st.push(val1 - val2);
                    break;
                case '*':
                    st.push(val1 * val2);
                    break;
                case '/':
                    st.push(val1 / val2);
                    break;
                case '^': {
                    int result = 1;
                    for (int i = 0; i < val2; i++)
                        result *= val1;
                    st.push(result);
                    break;
                }
            }
        }
    }

    return st.top();
}

int main() {
    string postfix;

    cout << "Enter Postfix Expression: ";
    cin >> postfix;

    cout << "Result = " << evaluatePostfix(postfix);

    return 0;
}
