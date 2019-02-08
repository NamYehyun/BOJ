#include <iostream>
#include <vector>

using namespace std;


int solve(int n, vector<int>& price, vector<int>& memo) {
    if (memo[n] != -1) {
        return memo[n];
    } else {
        int max = price[n];
        for (int i = 1; i < n; ++i) {
            int candidate = solve(i, price, memo) + price[n-i];
            if (max < candidate) {
                max = candidate;
            }
        }

        return memo[n] = max;
    }
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> price(n+1);
    for (int i = 1; i <= n; ++i) {
        cin >> price[i];
    }

    vector<int> memo(n+1, -1);

    cout << solve(n, price, memo) << endl;

    return EXIT_SUCCESS;
}

