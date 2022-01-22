#include <bits/stdc++.h>
using namespace std;

int main() {

    priority_queue<int> max_heap; // By default -> max heap
    max_heap.push(3);
    max_heap.push(1);
    max_heap.push(5);
    max_heap.push(4);
    max_heap.push(2);
    max_heap.push(4);

    while (!max_heap.empty()) {
        cout << max_heap.top() << " ";
        max_heap.pop();
    }
    cout << endl;
    // Output: 5 4 4 3 2 1


    priority_queue<int> min_heap;
    min_heap.push(-3);
    min_heap.push(-1);
    min_heap.push(-5);
    min_heap.push(-4);
    min_heap.push(-2);
    min_heap.push(-4);

    while (!min_heap.empty()) {
        cout << -min_heap.top() << " ";
        min_heap.pop();
    }
    cout << endl;
    // Output: 1 2 3 4 4 5


    priority_queue<int, vector<int>, greater<int>> actual_min_heap;
    actual_min_heap.push(3);
    actual_min_heap.push(1);
    actual_min_heap.push(5);
    actual_min_heap.push(4);
    actual_min_heap.push(2);
    actual_min_heap.push(4);

    while (!actual_min_heap.empty()) {
        cout << actual_min_heap.top() << " ";
        actual_min_heap.pop();
    }
    cout << endl;
}