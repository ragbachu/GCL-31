#include<bits/stdc++.h>
using namespace std;

// Each element is pushed exactly once in the stack => each element can be popped at most once from the stack
// Therefore, the maximum number of push and pop operations summed up over ALL the iterations is 2*n => O(n)

// TC: O(n)
// Aux Space: O(n)

vector<int> next_greater(vector<int> arr) {
    int n = arr.size();
    stack<int> helper; 

    vector<int> result(n);
    for (int i = n - 1; i >= 0; i--) {

        while (!helper.empty() and helper.top() <= arr[i]) {
            helper.pop();
        }

        if (helper.empty()) {
            result[i] = -1;
        }
        else {
            result[i] = helper.top();
        }

        helper.push(arr[i]);
    }

    return result;
}

int main() {

    vector<int> res = next_greater({6, 10, 90, 8, 5, 7});
    for (int i : res) {
        cout << i << " ";
    }
    cout << endl;

    res = next_greater({1, 2, 3, 4, 5});
    for (int i : res) {
        cout << i << " ";
    }
    cout << endl;

    res = next_greater({5, 4, 3, 2, 1});
    for (int i : res) {
        cout << i << " ";
    }
    cout << endl;
}