#include<bits/stdc++.h>
using namespace std;

bool is_safe(int i, int j, int n, int m) {

    return (i >= 0 and i < n and j >= 0 and j < m);
}

void dfs(vector<vector<int>> &adj, int current, vector<bool> &visited) {

    visited[current] = true;
    for (int i : adj[current]) {
        if (!visited[i]) {
            dfs(adj, i, visited);
        }
    }
}

int count_islands(vector<vector<int>> arr) {

    int n = arr.size();
    int m = arr[0].size();

    vector<int> dx = {-1, -1, -1, 0, 0, 1, 1, 1};
    vector<int> dy = {-1, 0, 1, -1, 1, -1, 0, 1};

    int V = n*m;
    vector<vector<int>> adj(V);

    // Creating the graph and connecting every set of adjacent land cells.
    // Each cell is numbered according to the formula: (i*num_of_columns + j).
    for (int i = 0; i < n; i++) {

        for (int j = 0; j < m; j++) {

            if (arr[i][j] == 0) continue;

            int current_cell = i*m + j;
            
            for (int k = 0; k < 8; k++) {

                int adj_i = i + dx[k];
                int adj_j = j + dy[k];

                if (is_safe(adj_i, adj_j, n, m) and arr[adj_i][adj_j] == 1) {

                    int adj_cell = adj_i*m + adj_j;
                    adj[current_cell].push_back(adj_cell);
                }
            }
        }
    }


    // Counting the number of disconnected components in the graph.
    vector<bool> visited(V, false);
    int result = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            int current_cell = i*m + j;
            if (arr[i][j] == 1 and !visited[current_cell]) {
                result++;
                dfs(adj, current_cell, visited);
            }
        }
    }

    return result;
}

int main() {

    cout << count_islands({{0, 1, 1, 1, 0, 0, 0},
                           {0, 0, 1, 1, 0, 1, 0}});
}