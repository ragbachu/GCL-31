#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(log(n))
// Aux space: O(1)
// Space complexity: O(n)

vector<int> first_and_last_occ(vector<int> arr, int x) {
    int n = arr.size();

    int first_occ = -1;
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == x) {
            first_occ = mid;
            high = mid - 1;
        }
        else if (arr[mid] > x) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    if (first_occ == -1) { // Element x is not present in the array.
        return {-1, -1};
    }


    int last_occ = -1;
    low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == x) {
            last_occ = mid;
            low = mid + 1;
        }
        else if (arr[mid] > x) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    return {first_occ, last_occ};
}

int main() {

    vector<int> res = first_and_last_occ({1, 3, 5, 5, 5, 5, 67, 123, 125}, 5);
    cout << res[0] << " "  << res[1] << endl;

    res = first_and_last_occ({1, 3, 5, 5, 5, 5, 7, 123, 125}, 7);
    cout << res[0] << " "  << res[1] << endl;
}