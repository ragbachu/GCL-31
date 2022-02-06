#include<bits/stdc++.h>
using namespace std;

bool detect_cycle_helper(vector<vector<int>> &adj, int current, vector<bool> &visited, int parent) {

    visited[current] = true;

    for (int j : adj[current]) {

        // If there is a visited adjacent node which is not the parent of the current node, then it means
        // the graph contains a cycle. Therefore, we will return true.
        if (visited[j] and j != parent) {
            return true;
        }

        // If the DFS call to the unvisited adjacent node returns true, it means the graph contains a cycle.
        if (!visited[j] and detect_cycle_helper(adj, j, visited, current)) {
            return true;
        }
    }

    return false;
}

bool detect_cycle(vector<vector<int>> adj) {

    int V = adj.size();
    vector<bool> visited(V, false);

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (detect_cycle_helper(adj, i, visited, -1)) {
                return true;
            }
        }
    }
    return false;
}

int main() {

    cout << detect_cycle({{1}, {0, 2}, {1}}) << endl;

    cout << detect_cycle({{1, 2}, {0, 2}, {0, 1}}) << endl;

    cout << detect_cycle({{}, {2, 3}, {1, 3}, {1, 2}}) << endl;

    cout << detect_cycle({{1, 2}, {0}, {0, 3, 4}, {2, 4}, {2, 3}}) << endl;
}