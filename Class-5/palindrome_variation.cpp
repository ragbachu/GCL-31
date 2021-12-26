#include<bits/stdc++.h>
using namespace std;

bool is_alpha_numeric(char ch) {

    return ((ch >= 'a' and ch <= 'z') or 
            (ch >= 'A' and ch <= 'Z') or
            (ch >= '0' and ch <= '9'));
}

bool are_same(char ch1, char ch2) {
    return ((ch1 == ch2) or
            (ch1 - 'a' + 'A' == ch2) or
            (ch1 - 'A' + 'a' == ch2));
}

bool is_palindrome(string s) {

    int i = 0, j = s.length() - 1;
    while (i < j) {
        if (!is_alpha_numeric(s[i])) {
            i++;
        }
        else if (!is_alpha_numeric(s[j])) {
            j--;
        }
        else {
            if (are_same(s[i], s[j])) {
                i++;
                j--;
            }
            else {
                return false;
            }
        }
    }

    return true;
}

int main() {

    cout << is_palindrome("A man, a plan, a canal: Panama") << endl;
    cout << is_palindrome("race a car") << endl;
}