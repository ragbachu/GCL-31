#include<bits/stdc++.h>
using namespace std;

/*
Time Complexity: O(n)
Auxiliary space: O(1)
Space Complexity: O(n)
*/

int remove_duplicates(vector<int> &arr) {

    int n = arr.size();
    int i = 0;
    int new_size = 0;

    while (i < n) {
        int j = i + 1;
        while (j < n and arr[j] == arr[i]) {
            j++;
        }

        arr[new_size] = arr[i];
        new_size++;

        i = j;
    }

    return new_size;
}

int main() {

    vector<int> arr = {1, 1, 2, 3, 3, 3, 3};
    int sz = remove_duplicates(arr);

    for (int i = 0; i < sz; i++)
    {
        cout << arr[i] << " ";
    }
    
}