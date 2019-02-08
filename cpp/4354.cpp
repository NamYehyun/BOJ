#include <iostream>
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


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (true) {
        string line;
        cin >> line;

        if (line == ".") {
            break;
        }

        const int length = static_cast<int>(line.length());

        vector<int> pi(length+1, -1);
        set_pi(line, pi);

        int div = length - pi[length];
        cout << (length % div == 0 ? length / div : 1) << '\n';
    }

    return EXIT_SUCCESS;
}

