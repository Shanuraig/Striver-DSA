#include <bits/stdc++.h>
using namespace std;

class StackUsingQ {
public:
    queue<int> q;

    void push(int x) {
        int s = q.size();
        q.push(x);
        for (int i = 0; i < s; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    void pop() {
        if (q.empty()) {
            cout << "Stack Underflow\n";
            return;
        }
        q.pop();
    }

    int top() {
        if (q.empty()) {
            cout << "Stack is Empty\n";
            return -1;
        }
        return q.front(); // top is always at front
    }

    bool empty() {
        return q.empty();
    }

    int size() {
        return q.size();
    }
};

int main() {
    StackUsingQ st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top: " << st.top() << "\n";   // 30
    st.pop();
    cout << "Top after pop: " << st.top() << "\n"; // 20
    cout << "Size: " << st.size() << "\n"; // 2
    cout << "Is Empty? " << (st.empty() ? "Yes" : "No") << "\n"; // No

    st.pop();
    st.pop();
    st.pop(); // Underflow

    return 0;
}
