#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class StackUsingLL {
public:
    int currSize = 0;
    Node* head = NULL;   // head = top of stack

    void push(int x) {
        Node* temp = new Node(x);
        temp->next = head;
        head = temp;
        currSize++;
    }

    void pop() {
        if (head == NULL) {
            cout << "Stack Underflow\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        currSize--;
    }

    int peek() {   // renamed from top() to avoid conflict
        if (head == NULL) {
            cout << "Stack is Empty\n";
            return -1;
        }
        return head->data;
    }

    int size() {
        return currSize;
    }

    bool empty() {
        return head == NULL;
    }
};

int main() {
    StackUsingLL st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top: " << st.peek() << "\n";   // 30
    cout << "Size: " << st.size() << "\n";  // 3

    st.pop();
    cout << "Top after pop: " << st.peek() << "\n"; // 20

    st.pop();
    st.pop();
    st.pop();  // will print underflow

    cout << "Is Empty? " << (st.empty() ? "Yes" : "No") << "\n"; // Yes

    return 0;
}
