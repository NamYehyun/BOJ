#include <iostream>
#include <vector>

using namespace std;


inline int max(int a, int b) {
    return (a > b) ? a : b;
}


inline int max(int a, int b, int c) {
    return max(max(a, b), c);
}


int lcs_length(string str_a, string str_b, string str_c) {
    const int len_a = str_a.length();
    const int len_b = str_b.length();
    const int len_c = str_c.length();

    vector<vector<vector<int>>> memo(len_a+1, vector<vector<int>>(len_b+1, vector<int>(len_c+1, 0)));
    for (int i = 1; i <= len_a; ++i) {
        for (int j = 1; j <= len_b; ++j) {
            for (int k = 1; k <= len_c; ++k) {
                if (str_a[i-1] == str_b[j-1] && str_b[j-1] == str_c[k-1]) {
                    memo[i][j][k] = memo[i-1][j-1][k-1] + 1;
                } else {
                    memo[i][j][k] = max(memo[i-1][j][k], memo[i][j-1][k], memo[i][j][k-1]);
                }
            }
        }
    }

    return memo[len_a][len_b][len_c];
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    string a, b, c;
    cin >> a >> b >> c;

    cout << lcs_length(a, b, c) << endl;

    return EXIT_SUCCESS;
}

