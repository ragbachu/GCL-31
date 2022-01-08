#include<bits/stdc++.h>
using namespace std;

int count_set_bits(int n) {

    // TC: O(total number of bits in n)
    int result = 0;
    while (n != 0) {
        if ((n & 1) != 0) {
            result++;
        }

        n = (n >> 1);
    }

    return result;
}

int count_set_bits_optimized(int n) {

    // TC: O(number of set bits in n)
    int result = 0;
    while (n != 0) {
        n = (n & (n - 1));
        result++;
    }

    return result;
}

bool check_kth_bit(int n, int k) {

    if ((n & (1 << k)) != 0) {
        return true;
    }
    return false;
}

int main() {

    cout << count_set_bits(10) << endl;
    cout << count_set_bits(15) << endl;

    cout << count_set_bits_optimized(10) << endl;
    cout << count_set_bits_optimized(15) << endl;

    cout << check_kth_bit(10, 3) << endl;
    cout << check_kth_bit(10, 2) << endl;
}