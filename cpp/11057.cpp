#include <iostream>
#include <vector>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;

    vector<vector<int>> memo(n+1, vector<int>(10));

    for (int msd = 0; msd <= 9; ++msd) {
        memo[1][msd] = 1;
    }

    for (int len = 2; len <= n; ++len) {
        memo[len][0] = memo[len-1][0];
        for (int msd = 1; msd <= 9; ++msd) {
            memo[len][msd] = (memo[len][msd-1] + memo[len-1][msd]) % 10007;
        }
    }

    int acc = 0;
    for (int msd = 0; msd <= 9; ++msd) {
        acc = (acc + memo[n][msd]) % 10007;
    }

    cout << acc << endl;
    
    return EXIT_SUCCESS;
}

