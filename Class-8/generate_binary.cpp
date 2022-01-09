#include<bits/stdc++.h>
using namespace std;

vector<string> generate_binary(int n) {

    vector<string> result;
    queue<string> q;
    q.push("1");

    while (result.size() != n) {

        string current = q.front();
        q.pop();

        result.push_back(current);
        q.push(current + "0");
        q.push(current + "1");
    }

    return result;
}

int main() {

    vector<string> result = generate_binary(10);
    for (string i : result) {
        cout << i << endl;
    }
}