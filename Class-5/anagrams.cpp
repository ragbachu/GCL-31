#include<bits/stdc++.h>
using namespace std;

bool are_anagrams(string a, string b) {

    if (a.length() != b.length()) {
        return false;
    }

    /*
    'a' -> 0
    'b' -> 1
    ...
    'z' -> 25
    */
    vector<int> char_freq(26, 0);

    for (int i = 0; i < a.length(); i++) {
        char_freq[a[i] - 'a']++;
        char_freq[b[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++) {
        if (char_freq[i] != 0) {
            return false;
        }
    }

    return true;
}

int main() {

    cout << are_anagrams("act", "tac") << endl;
    cout << are_anagrams("aac", "cca") << endl;
}