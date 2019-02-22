#include <iostream>
#include <vector>

using namespace std;


int solve(int n, vector<int>& memo) {
    if (memo[n] != -1) {
        return memo[n];
    }

    int acc = 0;
    for (int i = 2; i < n; i += 2) {
        acc += solve(i, memo);
    }

    return memo[n] = solve(n-2, memo) + 2*acc + 2;
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> memo(n+1);
    for (int i = 1; i <= n; ++i) {
        memo[i] = (i % 2 == 0) ? -1 : 0;
    }

    memo[2] = 3;

    cout << solve(n, memo) << endl;

    return EXIT_SUCCESS;
}

