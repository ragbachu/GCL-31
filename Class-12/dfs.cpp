#include<bits/stdc++.h>
using namespace std;

// Adds a undirected edge from u to v and from v to u.
void add_undirected_edge(vector<vector<int>> &adj, int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void dfs_helper(vector<vector<int>> &adj, int current, vector<bool> &visited, vector<int> &result) {

    result.push_back(current);
    visited[current] = true;

    for (int adjacent_vertex: adj[current]) {
        if (!visited[adjacent_vertex]) {
            dfs_helper(adj, adjacent_vertex, visited, result);
        }
    }
}

vector<int> dfs(vector<vector<int>> &adj) {

    vector<int> result;
    int V = adj.size();

    vector<bool> visited(V, false); // Marking all the nodes as unvisited initially.

    dfs_helper(adj, 0, visited, result);
    return result;
}


int main() {

    int V = 7;
    vector<vector<int>> adj(V);
    add_undirected_edge(adj, 0, 1);
    add_undirected_edge(adj, 0, 2);
    add_undirected_edge(adj, 1, 3);
    add_undirected_edge(adj, 1, 4);
    add_undirected_edge(adj, 2, 4);
    add_undirected_edge(adj, 3, 4);
    add_undirected_edge(adj, 3, 5);
    add_undirected_edge(adj, 4, 5);
    add_undirected_edge(adj, 5, 6);

    vector<int> dfs_trav = dfs(adj);
    for (int i : dfs_trav) {
        cout << i << " ";
    }
}