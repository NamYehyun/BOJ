#include <iostream>
#include <vector>

using namespace std;


long long solve(int n, vector<long long>& memo) {
    if (memo[n] != -1) {
        return memo[n];
    } else {
        return memo[n] = solve(n-1, memo) + solve(n-2, memo);
    }
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;

    vector<long long> memo(n+1, -1);
    memo[1] = 1;
    memo[2] = 1;

    cout << solve(n, memo) << endl;

    return EXIT_SUCCESS;
}

