#include <iostream>
#include <vector>

using namespace std;


const long long DIV = 1000000007;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int N, L, R;
    cin >> N >> L >> R;

    vector<vector<vector<long long>>> memo(N+1, vector<vector<long long>>(L+1, vector<long long>(R+1, 0)));
    memo[1][1][1] = 1;
    for (int n = 2; n <= N; ++n) {
        for (int l = 1; (l <= n) && (l <= L); ++l) {
            for (int r = 1; (r <= n) && (r <= R); ++r) {
                memo[n][l][r] = ((n-2)*memo[n-1][l][r]) % DIV;
                memo[n][l][r] = (memo[n][l][r] + memo[n-1][l-1][r]) % DIV;
                memo[n][l][r] = (memo[n][l][r] + memo[n-1][l][r-1]) % DIV;
            }
        }
    }

    cout << memo[N][L][R] << endl;

    return EXIT_SUCCESS;
}

