#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(log(n))
// Aux space: O(1)
// Space complexity: O(1)

int floor_sqrt(int n) {

    if (n == 1) {
        return 1;
    }

    int low = 0, high = n / 2;
    int result = 0;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (mid * mid <= n) {
            result = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return result;
}

int main() {

    cout << floor_sqrt(0) << endl;
    cout << floor_sqrt(1) << endl;
    cout << floor_sqrt(2) << endl;
    cout << floor_sqrt(3) << endl;
    cout << floor_sqrt(25) << endl;
    cout << floor_sqrt(30) << endl;
}