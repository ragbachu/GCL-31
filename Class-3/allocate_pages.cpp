#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(n*log(sum))
// Aux space: O(1)
// Space complexity: O(n)

// Checks if it is possible to allocate atmost `mid` number of pages per student to atmost `m` number of students.
bool is_possible(vector<int> &arr, int m, int mid) {
    int n = arr.size();

    int student_count = 1, current_pages = 0;

    for (int i = 0; i < n; i++) {
        if (current_pages + arr[i] > mid) {
            student_count++;
            current_pages = arr[i];
        }
        else {
            current_pages += arr[i];
        }
    }

    return (student_count <= m);
}

int find_min_pages(vector<int> arr, int m) {

    int n = arr.size();
    if (n < m) {
        return -1;
    }

    int low = arr[0], high = arr[0];
    for (int i = 1; i < n; i++) {
        low = max(low, arr[i]);
        high += arr[i];
    }

    int result = high;
    while (low <= high) {

        int mid = (low + high) / 2;
        if (is_possible(arr, m, mid)) {
            result = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    return result;
}

int main() {

    cout << find_min_pages({10, 20, 10, 30}, 2) << endl;
    cout << find_min_pages({12, 34, 67, 90}, 2) << endl;
}
