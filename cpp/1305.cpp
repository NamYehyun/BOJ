#include <iostream>
#include <vector>

using namespace std;


void get_pi(string& pattern, vector<int>& pi) {
    const int length = pattern.length();

    pi.resize(length, 0);

    int cnd = 0;
    int pos = 1;
    while (pos < length) {
        while (cnd > 0 && pattern[pos] != pattern[cnd]) {
            cnd = pi[cnd-1];
        }

        if (pattern[pos] == pattern[cnd]) {
            pi[pos] = ++cnd;
        }
        
        ++pos;
    }

}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int length;
    cin >> length;

    string pattern;
    cin >> pattern;

    vector<int> pi;
    get_pi(pattern, pi);

    cout << length - pi[length-1] << endl;

    return EXIT_SUCCESS;
}

