#include<bits/stdc++.h>
using namespace std;

/*
Time Complexity: O(n + max_ending_element_of_any_range)
Auxiliary space: O(max_ending_element_of_any_range)
Space complexity: O(n + max_ending_element_of_any_range)
*/

int max_occurring_in_ranges(vector<int> L, vector<int> R) {

    int n = L.size();
    int mx = R[0];
    for (int i = 1; i < n; i++) {
        mx = max(mx, R[i]);
    }

    vector<int> freq(mx + 2, 0); // Initialzing all of the frequencies with 0.

    for (int i = 0; i < n; i++) {

        freq[L[i]]++;
        freq[R[i] + 1]--;
    }

    // Convert `freq` array into a `sum till here` array.
    for (int i = 1; i < freq.size(); i++) {
        freq[i] += freq[i - 1];
    }

    int result = 0;
    for (int i = 1; i < freq.size(); i++) {
        if (freq[result] < freq[i]) {
            result = i;
        }
    }

    return result;
}

int main() {

    cout << max_occurring_in_ranges({2, 1, 3}, {5, 3, 9}) << endl;
    cout << max_occurring_in_ranges({1, 4, 3, 1}, {15, 8, 5, 4}) << endl;
}