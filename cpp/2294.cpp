#include <iostream>
#include <vector>

using namespace std;


const int INF = 0x7f7f7f7f;


int solve(int sum, vector<int>& coin, vector<int>& memo) {
    if (sum <= 0) {
        return 0;
    }

    if (memo[sum] != -1) {
        return memo[sum];
    }

    int min_count = INF;
    for (int c: coin) {
        if (sum < c) {
            continue;
        }

        int count = solve(sum-c, coin, memo) + 1;
        if (min_count > count) {
            min_count = count;
        }
    }

    return memo[sum] = min_count;
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<int> coin(n);
    for (int i = 0; i < n; ++i) {
        cin >> coin[i];
    }

    vector<int> memo(k+1, -1);

    int ans = solve(k, coin, memo);

    cout << (ans < INF ? ans : -1) << endl;

    return EXIT_SUCCESS;
}

