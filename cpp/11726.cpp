#include <iostream>
#include <vector>

using namespace std;


const int N_MAX = 1000;
const int DIV = 10007;


int solve(int n, vector<int>& memo) {
    if (n < 0) {
        return 0;
    }

    if (memo[n] != -1) {
        return memo[n];
    } else {
        return memo[n] = (solve(n-1, memo) + solve(n-2, memo)) % DIV;
    }
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> memo(n+1, -1);
    memo[0] = 1;

    cout << solve(n, memo) << endl;

    return EXIT_SUCCESS;
}

