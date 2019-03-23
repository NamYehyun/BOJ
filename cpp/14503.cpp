#include <iostream>
#include <vector>

using namespace std;


const int dirty = 0;
const int blocked = 1;
const int cleaned = 2;


int nrow, ncol;


class Cleaner {
public:
    class Pos {
    public:
        int row, col;

        Pos(int _row, int _col): row(_row), col(_col) {};

        Pos operator+(const Pos& other) const {
            return Pos(row + other.row, col + other.col);
        }

        Pos operator-(const Pos& other) const {
            return Pos(row - other.row, col - other.col);
        }
    };

    const Pos dpos[4] = {Pos(-1, 0), Pos(0, 1), Pos(1, 0), Pos(0, -1)};

    Pos pos;
    int dir;
    vector<vector<int>>& board;

    Cleaner(int _row, int _col, int _dir, vector<vector<int>>& board)
        : pos(Pos(_row, _col)), dir(_dir), board(board) {};

    inline Pos left(void) {
        return pos + dpos[(dir + 3) % 4];
    }

    inline Pos back(void) {
        return pos - dpos[dir];
    }

    inline void turn_left(void) {
        dir = (dir + 3) % 4;
        return;
    }

    inline void go_forward(void) {
        pos = pos + dpos[dir];
        return;
    }

    inline void go_backward(void) {
        pos = pos - dpos[dir];
        return;
    }

    inline bool safe(Pos p) {
        return (0 <= p.row && p.row < nrow) && (0 <= p.col && p.col < ncol);
    }

    inline bool is_dirty(Pos p) {
        return safe(p) && board[p.row][p.col] == dirty;
    }

    inline bool is_blocked(Pos p) {
        return safe(p) && board[p.row][p.col] == blocked;
    }

    bool step(void) {
        board[pos.row][pos.col] = cleaned;
        
        for (int _ = 0; _ < 4; ++_) {
            if (is_dirty(left())) {
                turn_left();
                go_forward();
                return true;
            }

            turn_left();
        }

        if (!is_blocked(back())) {
            go_backward();
            return true;
        }

        return false;
    }

    void clean(void) {
        while (step()) {}
    }
};


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> nrow >> ncol;

    int row, col, dir;
    cin >> row >> col >> dir;

    vector<vector<int>> board(nrow, vector<int>(ncol));
    for (int row = 0; row < nrow; ++row) {
        for (int col = 0; col < ncol; ++col) {
            cin >> board[row][col];
        }
    }

    Cleaner c(row, col, dir, board);
    c.clean();

    int clean_cnt = 0;
    for (int row = 0; row < nrow; ++row) {
        for (int col = 0; col < ncol; ++col) {
            if (board[row][col] == cleaned) {
                ++clean_cnt;
            }
        }
    }

    cout << clean_cnt << endl;

    return EXIT_SUCCESS;
}

