#include <iostream>
#include <vector>

using namespace std;


const int dr[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dc[8] = {-1, 0, 1, 1, 1, 0, -1, -1};


void dfs(int r, int c, int R, int C, vector<vector<int>>& board) {
    auto safe = [&R, &C](int r, int c) -> bool {
        return (0 <= r && r < R) && (0 <= c && c < C);
    };

    board[r][c] = 0;

    for (int i = 0; i < 8; ++i) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (safe(nr, nc) && board[nr][nc]) {
            dfs(nr, nc, R, C, board);
        }
    }

    return;
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    while (true) {
        int nrow, ncol;
        cin >> ncol >> nrow;

        if (!nrow && !ncol) {
            break;
        }

        vector<vector<int>> board(nrow, vector<int>(ncol));
        for (int row = 0; row < nrow; ++row) {
            for (int col = 0; col < ncol; ++col) {
                cin >> board[row][col];
            }
        }

        int cnt = 0;
        for (int row = 0; row < nrow; ++row) {
            for (int col = 0; col < ncol; ++col) {
                if (board[row][col]) {
                    dfs(row, col, nrow, ncol, board);
                    ++cnt;
                }
            }
        }

        cout << cnt << '\n';
    }
    
    return EXIT_SUCCESS;
}

