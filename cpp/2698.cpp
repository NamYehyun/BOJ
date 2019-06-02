#include <iostream>
#include <vector>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    const int max_n = 100, max_k = 100;

    vector<vector<int>> memo_0(max_n+1, vector<int>(max_k+1, 0));
    vector<vector<int>> memo_1(max_n+1, vector<int>(max_k+1, 0));

    memo_0[1][0] = 1;
    memo_1[1][0] = 1;

    for (int len = 2; len <= max_n; ++len) {
        for (int cnt = 0; cnt <= len-1; ++cnt) {
            memo_0[len][cnt] = memo_0[len-1][cnt] + memo_1[len-1][cnt];
            memo_1[len][cnt] = memo_0[len-1][cnt] + ((cnt >= 1) ? memo_1[len-1][cnt-1] : 0);
        }
    }

    int num_test;
    cin >> num_test;
    while (num_test--) {
        int n, k;
        cin >> n >> k;

        cout << memo_0[n][k] + memo_1[n][k] << '\n';
    }

    return EXIT_SUCCESS;
}

