#include<bits/stdc++.h>
using namespace std;

class Queue {
    public:
    stack<int> s1;
    stack<int> s2;

    Queue() {}

    void push(int a) {
        // TC: O(1)
        s1.push(a);
    }

    int pop() { // Pop the front element of the queue and return it.
        // TC: O(n)
        if (s1.empty()) {
            return -1;
        }

        // Transfer the elements from s1 to s2.
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        int result = s2.top();
        s2.pop();

        // Transfer back.
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }

        return result;
    }

    int size() {
        return s1.size();
    }

    bool is_empty() {
        return s1.empty();
    }
};

int main() {

    Queue q;
    q.push(1);
    q.push(2);
    cout << q.pop() << endl;
    q.push(3);
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;
}