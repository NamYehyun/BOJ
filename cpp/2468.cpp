#include <iostream>
#include <vector>

using namespace std;


const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};


void dfs(int r, int c, int size, vector<vector<int>>& board) {
    auto safe = [&size](int r, int c) -> bool {
        return (0 <= r && r < size) && (0 <= c && c < size);
    };

    board[r][c] = 0;

    for (int i = 0; i < 4; ++i) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (safe(nr, nc) && board[nr][nc]) {
            dfs(nr, nc, size, board);
        }
    }

    return;
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    auto max = [](int a, int b) -> int {
        return (a > b) ? a : b;
    };

    int size;
    cin >> size;

    vector<vector<int>> board(size, vector<int>(size));

    int max_height = 0;
    for (int row = 0; row < size; ++row) {
        for (int col = 0; col < size; ++col) {
            int height;
            cin >> height;

            board[row][col] = height;
            max_height = max(height, max_height);
        }
    }

    int max_cnt = 0;
    for (int height = 0; height <= max_height; ++height) {
        vector<vector<int>> new_board(size, vector<int>(size));
        for (int row = 0; row < size; ++row) {
            for (int col = 0; col < size; ++col) {
                new_board[row][col] = max(board[row][col] - height, 0);
            }
        }

        int cnt = 0;
        for (int row = 0; row < size; ++row) {
            for (int col = 0; col < size; ++col) {
                if (new_board[row][col]) {
                    dfs(row, col, size, new_board);
                    ++cnt;
                }
            }
        }

        max_cnt = max(cnt, max_cnt);
    }
    
    cout << max_cnt << endl;

    return EXIT_SUCCESS;
}

