#include <bits/stdc++.h>
using namespace std;


// Time complexity: O(k*k * log(k))
// Aux Space: O(k)
vector<int> merge_k_sorted_arrays(vector<vector<int>> arr) {

    /*
    pair<int, pair<int, int>> => p

    p.first = -arr[i][j]
    p.second.first = i
    p.second.second = j
    */

    priority_queue<pair<int, pair<int, int>>> pq;
    int k = arr.size();

    // Push the 0th element of all arrays into the priority queue
    for (int i = 0; i < k; i++) {
        pq.push({-arr[i][0], {i, 0}});
    }

    vector<int> result;
    while (!pq.empty()) {

        pair<int, pair<int, int>> current = pq.top();
        pq.pop();

        // Popping the minimum element from the priority queue and storing its indexes (i, j).
        int value = -current.first;
        int i = current.second.first;
        int j = current.second.second;

        result.push_back(value);

        // If there's an element to the right of the current element, it will be pushed in the pq.
        if (j + 1 < k) {
            pq.push({-arr[i][j + 1], {i, j + 1}});
        }
    }

    return result;
}

int main() {


    vector<int> result = merge_k_sorted_arrays({{5, 10, 15},
                                                {6, 9, 11},
                                                {1, 4, 7}});

    for (int i : result) {
        cout << i << " ";
    }
}