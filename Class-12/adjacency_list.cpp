#include<bits/stdc++.h>
using namespace std;

// Adds a directed edge from u to v.
void add_edge(vector<vector<int>> &adj, int u, int v) {
    // adj.get(u).add(v); (for JAVA)
    adj[u].push_back(v);
}

void print_adj_list(vector<vector<int>> &adj) {

    for (int i = 0; i < adj.size(); i++) {
        cout << i << " -> ";
        for (int j = 0; j < adj[i].size(); j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {

    int V = 5;
    vector<vector<int>> adj(V);
    add_edge(adj, 0, 1);
    add_edge(adj, 0, 4);
    add_edge(adj, 1, 0);
    add_edge(adj, 1, 2);
    add_edge(adj, 1, 3);
    add_edge(adj, 1, 4);
    add_edge(adj, 2, 1);
    add_edge(adj, 2, 3);
    add_edge(adj, 3, 1);
    add_edge(adj, 3, 2);
    add_edge(adj, 3, 4);
    add_edge(adj, 4, 0);
    add_edge(adj, 4, 1);
    add_edge(adj, 4, 3);

    print_adj_list(adj);
}