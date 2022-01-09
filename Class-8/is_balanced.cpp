#include<bits/stdc++.h>
using namespace std;


// TC: O(len)
// Aux Space: O(len)

bool are_equivalent(char cl, char op) {

    if (op == '(') return (cl == ')');
    if (op == '[') return (cl == ']');
    if (op == '{') return (cl == '}');

    return false;
}

bool is_balanced(string s) {

    stack<char> helper;
    for (int i = 0; i < s.length(); i++) {

        if (s[i] == '(' or s[i] == '[' or s[i] == '{') {
            helper.push(s[i]);
        }
        else {
            if (helper.empty()) {
                return false;
            }
            if (are_equivalent(s[i], helper.top()) == false) {
                return false;
            }

            helper.pop();
        }
    }

    return helper.empty();
}

int main() {

    cout << is_balanced("{([])}") << endl;
    cout << is_balanced("([]") << endl;
    cout << is_balanced("(]]]]") << endl;
    cout << is_balanced("{[}]") << endl;
}