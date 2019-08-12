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


void kmp(string& text, string& pattern, vector<int>& ans) {
    const int length_t = text.length();
    const int length_p = pattern.length();

    vector<int> pi;
    get_pi(pattern, pi);

    int cnd = 0;
    int pos = 0;
    while (pos < length_t) {
        while (cnd > 0 && text[pos] != pattern[cnd]) {
            cnd = pi[cnd-1];
        }

        if (text[pos] == pattern[cnd]) {
            if (cnd == length_p-1) {
                ans.push_back(pos-cnd+1);
                cnd = pi[cnd];
            } else {
                ++cnd;
            }
        }

        ++pos;
    }

    return;
}


inline int gcd(int a, int b) {
    return (b == 0) ? a : gcd(b, a % b);
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int length;
    cin >> length;
    
    string text = "";
    for (int i = 0; i < length; ++i) {
        char c;
        cin >> c;
        text += c;
    }

    text = text + text.substr(0, length-1);

    string pattern = "";
    for (int i = 0; i < length; ++i) {
        char c;
        cin >> c;
        pattern += c;
    }

    vector<int> ans;
    kmp(text, pattern, ans);

    int cnt = ans.size();
    int div = gcd(cnt, length);

    cout << (cnt/div) << "/" << (length/div) << endl;

    return EXIT_SUCCESS;
}

