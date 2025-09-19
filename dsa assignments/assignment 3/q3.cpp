#include <iostream>
#include <stack>
using namespace std;

bool isBalanced(string expr) {
    stack<char> st;
    for (char c : expr) {
        if (c == '(' || c == '{' || c == '[') st.push(c);
        else if (c == ')' || c == '}' || c == ']') {
            if (st.empty()) return false;
            char top = st.top();
            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '[')) return false;
            st.pop();
        }
    }
    return st.empty();
}

int main() {
    string expr;
    cout << "Enter expression: ";
    cin >> expr;

    if (isBalanced(expr)) cout << "Balanced";
    else cout << "Not Balanced";
    return 0;
}