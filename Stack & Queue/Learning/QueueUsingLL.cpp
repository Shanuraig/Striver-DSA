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

class QueueUsingLL {
public:
    Node* start = NULL;
    Node* end = NULL;
    int currSize = 0;

    void push(int x) {
        Node* temp = new Node(x);
        if (start == NULL) {
            start = end = temp;
        } else {
            end->next = temp;
            end = temp;  // move end forward
        }
        currSize++;
    }

    void pop() {
        if (start == NULL) {
            cout << "Queue Underflow\n";
            return;
        }
        Node* temp = start;
        start = start->next;
        if (start == NULL) end = NULL; // if queue becomes empty
        delete temp;
        currSize--;
    }

    int peek() {
        if (start == NULL) {
            cout << "Queue is Empty\n";
            return -1;
        }
        return start->data;
    }

    int size() {
        return currSize;
    }

    bool empty() {
        return currSize == 0;
    }
};

int main() {
    QueueUsingLL q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front: " << q.peek() << "\n";   // 10
    cout << "Size: " << q.size() << "\n";    // 3

    q.pop();
    cout << "Front after pop: " << q.peek() << "\n"; // 20

    q.pop();
    q.pop();
    q.pop();  // Underflow

    cout << "Is Empty? " << (q.empty() ? "Yes" : "No") << "\n"; // Yes

    return 0;
}
