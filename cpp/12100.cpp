#include <iostream>
#include <vector>

using namespace std;


inline int max(int a, int b) {
    return (a > b) ? a : b;
}


class Game {
public:
    const int UP = 0;
    const int DOWN = 1;
    const int LEFT = 2;
    const int RIGHT = 3;

    int size;
    vector<vector<int>> board;

    Game(int _size, vector<vector<int>>& _board): size(_size), board(_board) {}

    int largest_elt(void) {
        int elt = 0;
        for (int row = 0; row < size; ++row) {
            for (int col = 0; col < size; ++col) {
                elt = max(elt, board[row][col]);
            }
        }

        return elt;
    }

    void move_up(void) {
        for (int col = 0; col < size; ++col) {
            int crow = 0;
            while (crow < size) {
                while ((crow < size) && !board[crow][col])
                    ++crow;

                if (size <= crow)
                    break;

                int nrow = crow + 1;
                while ((nrow < size) && !board[nrow][col])
                    ++nrow;

                if (size <= nrow)
                    break;

                if (board[crow][col] == board[nrow][col]) {
                    board[crow][col] += board[nrow][col];
                    board[nrow][col] = 0;
                    crow = nrow + 1;
                } else {
                    crow = nrow;
                }
            }
        }

        for (int row = 1; row < size; ++row) {
            for (int col = 0; col < size; ++col) {
                if (!board[row-1][col]) {
                    int r = row;
                    while ((r >= 1) && !board[r-1][col]) {
                        board[r-1][col] = board[r][col];
                        board[r][col] = 0;
                        --r;
                    }
                }
            }
        }

        return;
    }

    void move_down(void) {
        for (int col = 0; col < size; ++col) {
            int crow = size - 1;
            while (crow >= 0) {
                while ((crow >= 0) && !board[crow][col])
                    --crow;

                if (crow < 0)
                    break;

                int nrow = crow - 1;
                while ((nrow >= 0) && !board[nrow][col])
                    --nrow;

                if (nrow < 0)
                    break;

                if (board[crow][col] == board[nrow][col]) {
                    board[crow][col] += board[nrow][col];
                    board[nrow][col] = 0;
                    crow = nrow - 1;
                } else {
                    crow = nrow;
                }
            }
        }

        for (int row = size-2; row >= 0; --row) {
            for (int col = 0; col < size; ++col) {
                if (!board[row+1][col]) {
                    int r = row;
                    while ((r <= size - 2) && !board[r+1][col]) {
                        board[r+1][col] = board[r][col];
                        board[r][col] = 0;
                        ++r;
                    }
                }
            }
        }

        return;
    }

    void move_left(void) {
        for (int row = 0; row < size; ++row) {
            int ccol = 0;
            while (ccol < size) {
                while ((ccol < size) && !board[row][ccol])
                    ++ccol;

                if (size <= ccol)
                    break;

                int ncol = ccol + 1;
                while ((ncol < size) && !board[row][ncol])
                    ++ncol;

                if (size <= ncol)
                    break;

                if (board[row][ccol] == board[row][ncol]) {
                    board[row][ccol] += board[row][ncol];
                    board[row][ncol] = 0;
                    ccol = ncol + 1;
                } else {
                    ccol = ncol;
                }
            }
        }

        for (int col = 1; col < size; ++col) {
            for (int row = 0; row < size; ++row) {
                if (!board[row][col-1]) {
                    int c = col;
                    while ((c >= 1) && !board[row][c-1]) {
                        board[row][c-1] = board[row][c];
                        board[row][c] = 0;
                        --c;
                    }
                }
            }
        }

        return;
    }

    void move_right(void) {
        for (int row = 0; row < size; ++row) {
            int ccol = size - 1;
            while (ccol >= 0) {
                while ((ccol >= 0) && !board[row][ccol])
                    --ccol;

                if (ccol < 0)
                    break;

                int ncol = ccol - 1;
                while ((ncol >= 0) && !board[row][ncol])
                    --ncol;

                if (ncol < 0)
                    break;

                if (board[row][ccol] == board[row][ncol]) {
                    board[row][ccol] += board[row][ncol];
                    board[row][ncol] = 0;
                    ccol = ncol - 1;
                } else {
                    ccol = ncol;
                }
            }
        }

        for (int col = size-2; col >= 0; --col) {
            for (int row = 0; row < size; ++row) {
                if (!board[row][col+1]) {
                    int c = col;
                    while ((c <= size - 2) &&!board[row][c+1]) {
                        board[row][c+1] = board[row][c];
                        board[row][c] = 0;
                        ++c;
                    }
                }
            }
        }


        return;
    }

    void move(int dir) {
        if (dir == UP) move_up();
        if (dir == DOWN) move_down();
        if (dir == LEFT) move_left();
        if (dir == RIGHT) move_right();
    }
};


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int size;
    cin >> size;

    vector<vector<int>> board(size, vector<int>(size, 0));
    for (int row = 0; row < size; ++row) {
        for (int col = 0; col < size; ++col) {
            cin >> board[row][col];
        }
    }

    int ans = 0;
    for (int dir1 = 0; dir1 < 4; ++dir1)
    for (int dir2 = 0; dir2 < 4; ++dir2)
    for (int dir3 = 0; dir3 < 4; ++dir3)
    for (int dir4 = 0; dir4 < 4; ++dir4)
    for (int dir5 = 0; dir5 < 4; ++dir5) {
        vector<vector<int>> tmp_board = board;
        Game game(size, tmp_board);

        game.move(dir1);
        game.move(dir2);
        game.move(dir3);
        game.move(dir4);
        game.move(dir5);

        ans = max(ans, game.largest_elt());
    }

    cout << ans << endl;

    return EXIT_SUCCESS;
}

