#include <iostream>
#include <vector>

using namespace std;


void set_pi(string& line, vector<int>& pi) {
    const int length = static_cast<int>(line.length());

    int pos = 1;
    int cnd = 0;
    pi[cnd] = -1;
    while (pos < length) {
        if (line[pos] == line[cnd]) {
            pi[pos] = pi[cnd];
        } else {
            pi[pos] = cnd;
            cnd = pi[cnd];
            while (cnd >= 0 && line[pos] != line[cnd]) {
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
    string line;
    cin >> line;

    int length = line.length();
    int max_len = 0;
    while (length) {
        vector<int> pi(length+1, -1);
        set_pi(line, pi);

        for (int len: pi) {
            if (max_len < len) {
                max_len = len;
            }
        }

        --length;
        line = line.substr(1, length);        
    }

    cout << max_len << endl;

    return EXIT_SUCCESS;
}

