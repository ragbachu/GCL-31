#include<bits/stdc++.h>
using namespace std;

bool detect_cycle_helper(vector<vector<int>> &adj, int current, vector<bool> &visited, vector<bool> &rec_stack) {

    if (visited[current]) {
        return false;
    }

    visited[current] = true;
    rec_stack[current] = true;

    for (int j : adj[current]) {

        // If the current adjacent node (j) is already a part of the recursive stack,
        // it means that there is a path from `j` back to `j`. In this case, we will return true.
        if (rec_stack[j]) {
            return true;
        }

        // If the DFS call to any adjacent node returns true, we will return true.
        if (detect_cycle_helper(adj, j, visited, rec_stack)) {
            return true;
        }
    }

    // After we backtrack, the `current` node will no more be a part of the recursive stack.
    rec_stack[current] = false;
    return false;
}

bool detect_cycle(vector<vector<int>> adj) {

    int V = adj.size();
    vector<bool> visited(V, false);
    vector<bool> rec_stack(V, false); // Currently, no node is a part of the recursive stack.

    for (int i = 0; i < V; i++) {
        if (detect_cycle_helper(adj, i, visited, rec_stack)) {
            return true;
        }
    }

    return false;
}

int main() {

}