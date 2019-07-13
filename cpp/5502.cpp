#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;


inline int max(int a, int b) {
    return (a > b) ? a : b;
}


int lcs_length(const string& str1, const string& str2) {
    const int len1 = str1.length();
    const int len2 = str2.length();
    vector<vector<int>> memo(len1+1, vector<int>(len2+1, -1));

    /* function<int(int, int)> dp = [&dp, &str1, &str2, &memo](int pos1, int pos2) -> int {
        if (memo[pos1][pos2] != -1) {
            return memo[pos1][pos2];
        }

        if (pos1 == 0 || pos2 == 0) {
            return memo[pos1][pos2] = 0;
        }

        if (str1[pos1-1] == str2[pos2-1]) {
            return memo[pos1][pos2] = dp(pos1-1, pos2-1) + 1;
        } else {
            return memo[pos1][pos2] = max(dp(pos1-1, pos2), dp(pos1, pos2-1));
        }
    };

    return dp(len1, len2); */

    for (int pos1 = 0; pos1 <= len1; ++pos1) {
        memo[pos1][0] = 0;
    }

    for (int pos2 = 0; pos2 <= len2; ++pos2) {
        memo[0][pos2] = 0;
    }

    for (int pos1 = 1; pos1 <= len1; ++pos1) {
        for (int pos2 = 1; pos2 <= len2; ++pos2) {
            if (str1[pos1-1] == str2[pos2-1]) {
                memo[pos1][pos2] = memo[pos1-1][pos2-1] + 1;
            } else {
                memo[pos1][pos2] = max(memo[pos1-1][pos2], memo[pos1][pos2-1]);
            }
        }
    }

    return memo[len1][len2];
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int length;
    string word;
    cin >> length >> word;

    string word_rev = word;
    reverse(word_rev.begin(), word_rev.end());

    cout << length - lcs_length(word, word_rev) << endl;

    return EXIT_SUCCESS;
}

