#include <bits/stdc++.h>
using namespace std;

// precedence function
int priority(char c) {
    if(c == '^') return 3;
    else if(c == '*' || c == '/') return 2;
    else if(c == '+' || c == '-') return 1;
    else return -1;
}

// function to convert infix to postfix
string infixtopostfix(string s) {
    stack<char> st;
    string ans = "";

    for(int i=0; i<s.length(); i++) {
        char c = s[i];

        // If operand (letter or digit), add to output
        if((c >= 'A' && c <= 'Z') || 
           (c >= 'a' && c <= 'z') || 
           (c >= '0' && c <= '9')) {
            ans += c;
        }

        // If opening parenthesis, push to stack
        else if(c == '(') {
            st.push(c);
        }

        // If closing parenthesis, pop until '('
        else if(c == ')') {
            while(!st.empty() && st.top() != '(') {
                ans += st.top();
                st.pop();
            }
            if(!st.empty()) st.pop(); // pop '('
        }

        // If operator
        else {
            while(!st.empty() && priority(c) <= priority(st.top())) {
                // special case: ^ is right-associative
                if(c == '^' && st.top() == '^') break;

                ans += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    // Pop remaining operators
    while(!st.empty()) {
        ans += st.top();
        st.pop();
    }

    return ans;
}

int main() {
    string s;
    cout << "Enter Infix Expression: ";
    cin >> s;

    cout << "Postfix: " << infixtopostfix(s) << endl;

    return 0;
}
