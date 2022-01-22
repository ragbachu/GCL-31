#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n*log(n))
// Auxiliary space: O(n)
int kth_largest_element_using_max_heap(vector<int> arr, int k) {

    priority_queue<int> pq;
    for (int i = 0; i < arr.size(); i++) {
        pq.push(arr[i]);
    }

    // Popping the (k-1) largest elements.
    int i = 0;
    while (i < k - 1) {
        pq.pop();
        i++;
    }

    return pq.top();
}

// Time Complexity: O(n*log(n))
// Auxiliary space: O(k)
int kth_largest_element_using_min_heap(vector<int> arr, int k) {

    priority_queue<int, vector<int>, greater<int>> pq;

    // Push the first k element in the min heap.
    for (int i = 0; i < k; i++) {
        pq.push(arr[i]);
    }

    for (int i = k; i < arr.size(); i++) {
        if (arr[i] > pq.top()) {
            pq.pop(); // Popping out the minimum.
            pq.push(arr[i]);
        }
    }

    return pq.top();
}

int main() {

    cout << kth_largest_element_using_max_heap({3, 5, 4, 2, 9}, 3) << endl;
    cout << kth_largest_element_using_min_heap({3, 5, 4, 2, 9}, 3) << endl;
}