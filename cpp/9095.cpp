#include <iostream>
#include <vector>

using namespace std;


const int N_MAX = 11;


long long solve(int n, vector<int>& memo) {
    if (n < 0) {
        return 0;
    }


    if (memo[n] != 0) {
        return memo[n];
    } else {
        return memo[n] = solve(n-1, memo) + solve(n-2, memo) + solve(n-3, memo);
    }
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    vector<int> memo(N_MAX+1, 0);
    memo[0] = 1;

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        cout << solve(n, memo) << '\n';
    }

    return EXIT_SUCCESS;
}

