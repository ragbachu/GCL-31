#include<bits/stdc++.h>
using namespace std;

vector<int> single_source_shortest_paths(vector<vector<int>> adj, int source) {

    int V = adj.size();
    vector<bool> visited(V, false);
    vector<int> distance(V, INT_MAX); // Setting all of the distances to infinity.

    queue<int> q;
    q.push(source);

    distance[source] = 0;
    visited[source] = true;

    while (!q.empty()) {

        int current = q.front();
        q.pop();

        for (int j : adj[current]) {
            if (!visited[j]) {
                visited[j] = true;
                distance[j] = distance[current] + 1;
                q.push(j);
            }
        }
    }

    return distance;
}

int main() {

    int source = 0;
    vector<int> result = single_source_shortest_paths({{1, 2},
                                                       {0, 3, 4},
                                                       {0, 4},
                                                       {1, 5},
                                                       {1, 2, 5},
                                                       {3, 4}}, source);


    cout << "Distances from " << source << endl;
    for (int i = 0; i < result.size(); i++) {
        cout << i << " -> " << result[i] << endl;
    }
}