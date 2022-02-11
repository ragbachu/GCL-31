#include<bits/stdc++.h>
using namespace std;

// TC: O(n*log(n))
// Aux Space: O(n)

// Taking {value, weight} pairs as inputs.
bool value_over_wt_comp(pair<int, int> &a, pair<int, int> &b) {

    return (a.first / (double)a.second) > (b.first / (double)b.second);
    // return a.first * b.second > b.first * a.second;
}


double get_max_value(vector<int> values, vector<int> weights, int W) {

    int n = values.size();
    vector<pair<int, int>> value_wt_pairs(n);
    for (int i = 0; i < n; i++) {
        value_wt_pairs[i] = {values[i], weights[i]};
    }

    sort(value_wt_pairs.begin(), value_wt_pairs.end(), value_over_wt_comp);

    double max_value = 0;

    for (int i = 0; i < n; i++) {    
        int current_value = value_wt_pairs[i].first;
        int current_weight = value_wt_pairs[i].second;

        if (current_weight <= W) {
            max_value += current_value;
            W -= current_weight;
        }
        else {
            max_value += (current_value * W) / (double)current_weight;
            W = 0;
            break;
        }
    }

    return max_value;
}

int main() {

    cout << get_max_value({60, 100, 120}, {10, 20, 30}, 50) << endl;
    cout << get_max_value({60, 100, 180}, {10, 20, 30}, 50) << endl;
}