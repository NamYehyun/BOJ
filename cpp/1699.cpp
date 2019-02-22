#include <iostream>
#include <vector>

using namespace std;


const int INF = 0x7f7f7f7f;

int solve(int n, vector<int>& memo) {
    if (memo[n] != -1) {
        return memo[n];
    }

    int min_count = INF;
    for (int i = 1; i*i < n; ++i) {
        int count = solve(n - i*i, memo) + 1;
        if (min_count > count) {
            min_count = count;
        }
    }

    return memo[n] = min_count;
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> memo(n+1, -1);
    for (int i = 1; i*i <= n; ++i) {
        memo[i*i] = 1;
    }

    cout << solve(n, memo) << endl;

    return EXIT_SUCCESS;
}

