#include <iostream>
#include <vector>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    vector<int> cnt('z'-'a'+1, 0);

    string line;
    while (getline(cin, line)) {
        for (const char& c: line) {
            if ('a' <= c && c <= 'z') {
                ++cnt[c-'a'];
            }
        }
    }

    int max_cnt = 0;
    for (char c = 'a'; c <= 'z'; ++c) {
        if (max_cnt < cnt[c-'a']) {
            max_cnt = cnt[c-'a'];
        }
    }

    for (char c = 'a'; c <= 'z'; ++c) {
        if (cnt[c-'a'] == max_cnt) {
            cout << c;
        }
    }
    cout << endl;

    return EXIT_SUCCESS;
}

