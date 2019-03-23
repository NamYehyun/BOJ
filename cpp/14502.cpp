#include <iostream>
#include <vector>

using namespace std;


const int blank = 0;
const int block = 1;
const int virus = 2;
const int infected = 3;

const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};


int nrow, ncol;


class Pos {
public:
    int row, col;
    Pos(int _row, int _col): row(_row), col(_col) {}
};


inline bool safe(int row, int col) {
    return (0 <= row && row < nrow) && (0 <= col && col < ncol);
}


void infect(int r, int c, vector<vector<int>>& board) {
    board[r][c] = infected;
    for (int i = 0; i < 4; ++i) {
        int row = r + dr[i];
        int col = c + dc[i];
        if (safe(row, col) && board[row][col] == blank) {
            infect(row, col, board);
        }
    }

    return;
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> nrow >> ncol;

    vector<Pos> candidate;
    vector<vector<int>> orig_board(nrow, vector<int>(ncol));
    for (int row = 0; row < nrow; ++row) {
        for (int col = 0; col < ncol; ++col) {
            cin >> orig_board[row][col];
            if (orig_board[row][col] == blank) {
                candidate.emplace_back(row, col);
            }
        }
    }

    int max_cnt = 0;
    int c_size = candidate.size();
    for (int x = 0; x < c_size; ++x) {
        for (int y = x+1; y < c_size; ++y) {
            for (int z = y+1; z < c_size; ++z) {
                vector<vector<int>> board = orig_board;
                board[candidate[x].row][candidate[x].col] = block;
                board[candidate[y].row][candidate[y].col] = block;
                board[candidate[z].row][candidate[z].col] = block;

                for (int row = 0; row < nrow; ++row) {
                    for (int col = 0; col < ncol; ++col) {
                        if (board[row][col] == virus) {
                            infect(row, col, board);
                        }
                    }
                }

                int cnt = 0;
                for (int row = 0; row < nrow; ++row) {
                    for (int col = 0; col < ncol; ++col) {
                        if (board[row][col] == blank) {
                            ++cnt;
                        }
                    }
                }

                max_cnt = (max_cnt < cnt) ? cnt : max_cnt;
            }
        }
    }

    cout << max_cnt << endl;

    return EXIT_SUCCESS;
}

