#include<bits/stdc++.h>
using namespace std;

// This function will return the LCS of s1[i...n-1] and s2[j...m-1]
// n-> length of s1
// m-> length of s2

// TC: O(n * m)
int LCS_helper(string &s1, string &s2, int i, int j, vector<vector<int>> &memo) {

    if (i == s1.length() or j == s2.length()) {
        return 0;
    }
    if (memo[i][j] != -1) {
        return memo[i][j];
    }

    int result = 0;

    if (s1[i] == s2[j]) {
        result = 1 + LCS_helper(s1, s2, i + 1, j + 1, memo);
    }
    else {
        result = max(LCS_helper(s1, s2, i + 1, j, memo), LCS_helper(s1, s2, i, j + 1, memo));
    }

    memo[i][j] = result;
    return result;
}

int LCS(string s1, string s2) {
    int n = s1.length(), m = s2.length();
    vector<vector<int>> memo(n, vector<int> (m, -1));
    return LCS_helper(s1, s2, 0, 0, memo);
}

int main() {

    cout << LCS("ABCDGH", "AEDFHR") << endl;
    cout << LCS("ABC", "AC") << endl;
}