#include<bits/stdc++.h>
using namespace std;

vector<string> get_individual_words(string s, char delim) {

    vector<string> words;
    string current_word = "";

    int i = 0;
    while (i < s.length()) {
        if (s[i] == delim) {
            words.push_back((current_word));
            current_word = "";
        }
        else {
            current_word.push_back(s[i]);
        }

        i++;
    }

    words.push_back(current_word);
    return words;
}

string reverse_words(string s) {

    vector<string> words = get_individual_words(s, '.');

    string result = "";
    for (int i = words.size() - 1; i >= 0; i--) {
        result += words[i];
        if (i != 0) {
            result += ".";
        }
    }

    return result;
}

int main() {

    cout << reverse_words("i.like.this.program.very.much") << endl;
    cout << reverse_words("pqr.mno") << endl;
}