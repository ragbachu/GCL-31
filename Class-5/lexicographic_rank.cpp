#include<bits/stdc++.h>
using namespace std;

vector<int> fact;
int mod = 1000003;

void precompute_factorials(int n) {
    fact = vector<int> (n + 1);
    fact[0] = 1;
    for (int i = 1; i < fact.size(); i++) {
        fact[i] = (fact[i - 1] * i) % mod;
    }
}

int find_rank(string s) {

    int n = s.length();
    precompute_factorials(n - 1);

    string s_sorted = s;
    sort(s_sorted.begin(), s_sorted.end());

    int result = 0;
    for (int i = 0; i < n - 1; i++) {

        // Count the number of smaller characters than s[i].
        int cnt_smaller = 0;
        for (int j = 0; j < n; j++) {
            if (s_sorted[j] == s[i]) {
                s_sorted[j] = '#';
                break;
            }

            if (s_sorted[j] != '#') {
                cnt_smaller++;
            }
        }

        result = (result + (cnt_smaller * fact[n - i - 1]) % mod) % mod;
    }

    return (result + 1) % mod;
}

int main() {

    cout << find_rank("view") << endl;
    cout << find_rank("cdba") << endl;
    cout << find_rank("acb") << endl;
    cout << find_rank("abc") << endl;
    cout << find_rank("cba") << endl;
}