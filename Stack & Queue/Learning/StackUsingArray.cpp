#include <bits/stdc++.h>
using namespace std;

class StackUsingArray {
public:
    int topIndex = -1;
    int st[10];

    void push(int x) {
        if (topIndex >= 9) {
            cout << "Stack Overflow\n";
            return;
        }
        topIndex++;
        st[topIndex] = x;
    }

    int pop() {
        if (topIndex == -1) {
            cout << "Stack Underflow\n";
            return -1;  // sentinel value
        }
        int el = st[topIndex];
        topIndex--;
        return el;
    }

    int peek() {   // renamed from top() to avoid conflict
        if (topIndex == -1) {
            cout << "Stack is Empty\n";
            return -1;
        }
        return st[topIndex];
    }

    int size() {
        return topIndex + 1;
    }

    bool empty() {
        return topIndex == -1;
    }
};

int main() {
    StackUsingArray st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    cout << "Popped: " << st.pop() << "\n";
    cout << "Current Top: " << st.peek() << "\n";
    cout << "Size: " << st.size() << "\n";
    cout << "Is Empty? " << (st.empty() ? "Yes" : "No") << "\n";

    return 0;
}
