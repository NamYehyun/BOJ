#include <iostream>
#include <vector>

using namespace std;


const int dr[2] = {0, 1};
const int dc[2] = {1, 0};


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<vector<int>> board(n, vector<int>(n));
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            cin >> board[r][c];
        }
    }

    vector<vector<long long>> count(n, vector<long long>(n, 0));

    count[0][0] = 1;
    for (int sum = 0; sum <= 2*(n-1)-1; ++sum) {
        for (int r = 0; r <= sum; ++r) {
            int c = sum-r;

            if ((0 <= r && r < n) && (0 <= c && c < n)) {
                for (int i = 0; i < 2; ++i) {
                    int row = r + board[r][c]*dr[i];
                    int col = c + board[r][c]*dc[i];
                    if ((0 <= row && row < n) && (0 <= col && col < n)) {
                        count[row][col] += count[r][c];
                    }
                }
            }
        }
    }

    cout << count[n-1][n-1] << endl;

    return EXIT_SUCCESS;
}

