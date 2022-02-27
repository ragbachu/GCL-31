#include<bits/stdc++.h>
using namespace std;

// TC: O(n*W)

vector<vector<int>> memo;
int max_value_helper(vector<int> &values, vector<int> &weights, int i, int W) {

    if (i == values.size() or W == 0) {
        return 0;
    }
    if (memo[i][W] != -1) {
        return memo[i][W];
    }

    int result = 0;
    if (weights[i] <= W) {
        result = max(values[i] + max_value_helper(values, weights, i + 1, W - weights[i]),
                     max_value_helper(values, weights, i + 1, W));
    }
    else {
        result = max_value_helper(values, weights, i + 1, W);
    }

    memo[i][W] = result;
    return result;
}

int max_value(vector<int> values, vector<int> weights, int W) {

    int n = values.size();
    memo = vector<vector<int>> (n + 1, vector<int> (W + 1, -1));
    return max_value_helper(values, weights, 0, W);
}

int max_value_bottom_up(vector<int> values, vector<int> weights, int W) {

    int n = values.size();
    vector<vector<int>> dp(n + 1, vector<int> (W + 1));
    
    // Building the base cases iteratively.
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    for (int j = 0; j <= W; j++) {
        dp[n][j] = 0;
    }

    for (int i = n - 1; i >= 0; i--) {
        for (int j = 1; j <= W; j++) {
            if (weights[i] <= j) {
                dp[i][j] = max(values[i] + dp[i + 1][j - weights[i]], dp[i + 1][j]);
            }
            else {
                dp[i][j] = dp[i + 1][j];
            }
        }
    }

    return dp[0][W];
}

int main() {

    cout << max_value({60, 100, 120}, {10, 20, 30}, 50) << endl;
    cout << max_value({60, 100, 120}, {10, 20, 50}, 50) << endl;

    cout << max_value_bottom_up({60, 100, 120}, {10, 20, 30}, 50) << endl;
    cout << max_value_bottom_up({60, 100, 120}, {10, 20, 50}, 50) << endl;
}
