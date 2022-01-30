#include<bits/stdc++.h>
using namespace std;

void dfs(unordered_map<string, vector<string>> &adj, string current, stack<string> &helper, 
            unordered_set<string> &unvisited) {

    // If the current string has already been visited, return.
    // That is, if it is not a part of the unvisited set.
    if (unvisited.find(current) == unvisited.end()) {
        return;
    }

    // Mark the current string as visited. That is, pop it out from the unvisited set.
    unvisited.erase(unvisited.find(current));

    for (string j : adj[current]) {
        dfs(adj, j, helper, unvisited);
    }

    helper.push(current);
}

int main() {
    unordered_map<string, vector<string>> adj;
    adj["A"] = {};
    adj["B"] = {"A"};
    adj["C"] = {"A", "B"};
    adj["D"] = {"A"};
    adj["E"] = {"D"};

    unordered_set<string> unvisited;
    unvisited.insert("A");
    unvisited.insert("B");
    unvisited.insert("C");
    unvisited.insert("D");
    unvisited.insert("E");

    stack<string> helper;
    while (!unvisited.empty()) {

        // Storing the current top string of the set.
        string current = *(unvisited.begin()); 
        
        dfs(adj, current, helper, unvisited);
    }


    vector<string> result;
    while (!helper.empty()) {
        result.push_back(helper.top());
        helper.pop();
    }

    for (string i : result) {
        cout << i << " ";
    }
}