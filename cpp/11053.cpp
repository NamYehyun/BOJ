#include <iostream>
#include <vector>

using namespace std;


int solve(int n, vector<int>& arr, vector<int>& memo) {
    if (memo[n] != -1) {
        return memo[n];
    } else {
        int memo_n = 1;
        for (int i = 0; i < n; ++i) {
            int memo_i = solve(i, arr, memo);
            if (arr[i] < arr[n] && memo_n < memo_i + 1) {
                memo_n = memo_i + 1;
            }
        }

        return memo[n] = memo_n;
    }
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    vector<int> memo(n, -1);
    solve(n-1, arr, memo);

    int max = memo[0];
    for (int i = 1; i < n; ++i) {
        if (max < memo[i]) {
            max = memo[i];
        }
    }

    cout << max << endl;

    return EXIT_SUCCESS;
}

