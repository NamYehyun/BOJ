#include <iostream>
#include <vector>

using namespace std;


const long long NIL = -1;


inline long long max(long long a, long long b) {
    return (a > b) ? a : b;
}


long long solve(int r, int c, int size, vector<vector<long long>>& board, vector<vector<long long>>& memo) {
    if (memo[r][c] != NIL) {
        return memo[r][c];
    }

    const int dr[4] = {-1, 0, 1, 0};
    const int dc[4] = {0, 1, 0, -1};

    auto safe = [size](int row, int col) -> bool {
        return (0 <= row && row < size) && (0 <= col && col < size);
    };

    long long max_adj = 0;
    for (int i = 0; i < 4; ++i) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (safe(nr, nc) && board[nr][nc] > board[r][c]) {
            max_adj = max(max_adj, solve(nr, nc, size, board, memo));
        }
    }

    return memo[r][c] = max_adj + 1;
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int size;
    cin >> size;

    vector<vector<long long>> board(size, vector<long long>(size));
    for (int row = 0; row < size; ++row) {
        for (int col = 0; col < size; ++col) {
            cin >> board[row][col];
        }
    }

    vector<vector<long long>> memo(size, vector<long long>(size, NIL));

    long long ans = 0;
    for (int row = 0; row < size; ++row) {
        for (int col = 0; col < size; ++col) {
            ans = max(ans, solve(row, col, size, board, memo));
        }
    }

    cout << ans << endl;

    return EXIT_SUCCESS;
}

