#include <bits/stdc++.h>
using namespace std;

class QueueUsingArray {
public:
    int start = -1;
    int end = -1;
    int q[10];
    int currsize = 0;

    void push(int x) {
        if (currsize == 10) {
            cout << "Queue Overflow\n";
            return;
        }
        if (currsize == 0) {
            start = 0;
            end = 0;
        } else {
            end = (end + 1) % 10;
        }
        q[end] = x;
        currsize++;
    }

    int pop() {
        if (currsize == 0) {
            cout << "Queue Underflow\n";
            return -1;
        }
        int el = q[start];
        if (currsize == 1) {
            start = end = -1;
        } else {
            start = (start + 1) % 10;
        }
        currsize--;
        return el;
    }

    int front() {
        if (currsize == 0) {
            cout << "Queue is Empty\n";
            return -1;
        }
        return q[start];
    }

    int size() {
        return currsize;
    }

    bool isempty() {
        return currsize == 0;
    }
};

int main() {
    QueueUsingArray q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front: " << q.front() << "\n";   // 10
    cout << "Size: " << q.size() << "\n";     // 3

    cout << "Popped: " << q.pop() << "\n";    // 10
    cout << "Front: " << q.front() << "\n";   // 20
    cout << "Is Empty? " << (q.isempty() ? "Yes" : "No") << "\n"; // No

    return 0;
}
