#include<bits/stdc++.h>
using namespace std;

// TC: O(n)
// Aux Space: O(n)
// Space complexity: O(n)

// {start index, end index}
vector<int> find_zero_sum_subarray(vector<int> arr) {
    int n = arr.size();

    unordered_map<int, int> mp;
    int sum_till_here = 0;

    for (int i = 0; i < n; i++) {
        sum_till_here += arr[i];
        if (sum_till_here == 0) {
            return {0, i};
        }
        if (mp.find(sum_till_here) != mp.end()) {
            return {mp[sum_till_here] + 1, i};
        }

        mp[sum_till_here] = i;
    }

    return {-1, -1};
}


bool check_zero_sum_subarray(vector<int> arr) {
    int n = arr.size();

    unordered_map<int, bool> mp;
    int sum_till_here = 0;

    for (int i = 0; i < n; i++) {
        sum_till_here += arr[i];
        if (sum_till_here == 0 or mp[sum_till_here]) {
            return true;
        }

        mp[sum_till_here] = true;
    }

    return false;
}

int main() {

    cout << check_zero_sum_subarray({4, 2, -3, 1, 6}) << endl;
    cout << check_zero_sum_subarray({1, -1, 3, 7, 8}) << endl;
    cout << check_zero_sum_subarray({1, 1, 3, 7, 8}) << endl;

    vector<int> res = find_zero_sum_subarray({4, 2, -3, 1, 6});
    cout << res[0] << " " << res[1] << endl;

    res = find_zero_sum_subarray({1, -1, 3, 7, 8});
    cout << res[0] << " " << res[1] << endl;

    res = find_zero_sum_subarray({1, 1, 3, 7, 8});
    cout << res[0] << " " << res[1] << endl;
}