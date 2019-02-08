#include <iostream>
#include <vector>

using namespace std;


int comb(int n, int r, vector<vector<int>>& memo) {
    if (memo[n][r] != -1) {
        return memo[n][r];
    }

    if (r == 0 || r == n) {
        return memo[n][r] = 1;
    } else {
        return memo[n][r] = comb(n-1, r-1, memo) + comb(n-1, r, memo);
    }
};


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int t;
    cin >> t;

    vector<vector<int>> memo(31, vector<int>(31, -1));

    while (t--) {
        int n, m;
        cin >> n >> m;

        cout << comb(m, n, memo) << '\n';
    }

    return EXIT_SUCCESS;
}

