#include<bits/stdc++.h>
using namespace std;

/*
Time complexity: O(n)
Aux space: O(n)
Space complexity: O(n)
*/

vector<int> product_except_self(vector<int> nums) {

    int n = nums.size();
    vector<int> pref(n);
    vector<int> suff(n);

    pref[0] = 1;
    for (int i = 1; i < n; i++) {
        pref[i] = pref[i - 1] * nums[i - 1];
    }

    suff[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--) {
        suff[i] = suff[i + 1] * nums[i + 1];
    }

    vector<int> answer(n);
    for (int i = 0; i < n; i++) {
        answer[i] = pref[i] * suff[i];
    }

    return answer;
}

int main() {
    vector<int> res = product_except_self({1, 2, 3, 4});
    for (int i : res) cout << i << " ";
    cout << endl;

    res = product_except_self({-1, 1, 0, -3, 3});
    for (int i : res) cout << i << " ";
    cout << endl;
}