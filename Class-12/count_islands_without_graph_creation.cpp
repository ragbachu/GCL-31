#include<bits/stdc++.h>
using namespace std;


bool is_safe(int i, int j, int n, int m) {

    return (i >= 0 and i < n and j >= 0 and j < m);
}

vector<int> dx = {-1, -1, -1, 0, 0, 1, 1, 1};
vector<int> dy = {-1, 0, 1, -1, 1, -1, 0, 1};

void dfs(vector<vector<int>> &arr, int i, int j) {

    arr[i][j] = 0; // Marking the current cell as visited.

    for (int k = 0; k < 8; k++) {
        int adj_i = i + dx[k];
        int adj_j = j + dy[k];

        if (is_safe(adj_i, adj_j, arr.size(), arr[i].size()) and arr[adj_i][adj_j] == 1) {
            dfs(arr, adj_i, adj_j);
        } 
    }
}

int count_islands(vector<vector<int>> arr) {

    int result = 0;
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[i].size(); j++) {
            if (arr[i][j] == 1) {
                result++;
                dfs(arr, i, j);
            }
        }
    }
    return result;
}

int main() {

    cout << count_islands({{0, 1, 1, 1, 0, 0, 0},
                           {0, 0, 1, 1, 0, 1, 0}});
}