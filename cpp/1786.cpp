#include <iostream>
#include <string>
#include <vector>

using namespace std;


void set_pi(string& pattern, vector<int>& pi) {
    const int length = static_cast<int>(pattern.length());

    int pos = 1;
    int cnd = 0;
    pi[cnd] = -1;
    while (pos < length) {
        if (pattern[pos] == pattern[cnd]) {
            pi[pos] = pi[cnd];
        } else {
            pi[pos] = cnd;
            cnd = pi[cnd];
            while (cnd >= 0 && pattern[pos] != pattern[cnd]) {
                cnd = pi[cnd];
            }
        }
        ++pos;
        ++cnd;
    }
    pi[pos] = cnd;

    return;
}


void search(string& text, string& pattern, vector<int>& match) {
    const int length_t = static_cast<int>(text.length());
    const int length_p = static_cast<int>(pattern.length());

    vector<int> pi(length_p+1, -1);
    set_pi(pattern, pi);

    int pos_t = 0;
    int pos_p = 0;
    while (pos_t < length_t) {
        if (text[pos_t] == pattern[pos_p]) {
            ++pos_t;
            ++pos_p;
            if (pos_p == length_p) {
                match.push_back(pos_t-pos_p);
                pos_p = pi[pos_p];
            }
        } else {
            pos_p = pi[pos_p];
            if (pos_p < 0) {
                ++pos_t;
                ++pos_p;
            }
        }
    }

    return;
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string text, pattern;
    getline(cin, text);
    getline(cin, pattern);

    vector<int> match;
    search(text, pattern, match);

    cout << match.size() << endl;
    for (int idx: match) {
        cout << idx+1 << ' ';
    }
    cout << endl;

    return EXIT_SUCCESS;
}

