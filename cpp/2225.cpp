#include <iostream>
#include <vector>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<vector<int>> memo(n+1, vector<int>(k+1, 0));
    for (int cnt = 1; cnt <= k; ++cnt) {
        memo[0][cnt] = 1;
    }

    for (int sum = 0; sum <= n; ++sum) {
        memo[sum][1] = 1;
    }

    for (int sum = 1; sum <= n; ++sum) {
        for (int cnt = 2; cnt <= k; ++cnt) {
            for (int acc = 0; acc <= sum; ++acc) {
                memo[sum][cnt] += memo[acc][cnt-1];
                memo[sum][cnt] %= 1000000000;
            }
        }
    }

    cout << memo[n][k] << endl;

    return EXIT_SUCCESS;
}

