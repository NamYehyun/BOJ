#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;


const bool white = false;
const bool black = true;

const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int nrow, ncol, nrec;
    cin >> nrow >> ncol >> nrec;

    vector<vector<bool>> board(nrow, vector<bool>(ncol, white));
    for (int rec = 0; rec < nrec; ++rec) {
        int r1, c1, r2, c2;
        cin >> c1 >> r1 >> c2 >> r2;

        for (int r = r1; r < r2; ++r) {
            for (int c = c1; c < c2; ++c) {
                board[r][c] = black;
            }
        }
    }

    function<bool(int, int)> safe = [&nrow, &ncol](int r, int c) -> bool {
        return (0 <= r && r < nrow) && (0 <= c && c < ncol);
    };

    function<int(int, int)> dfs = [&dfs, &safe, &board](int r, int c) -> int {
        board[r][c] = black;

        int acc = 1;
        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (safe(nr, nc) && (board[nr][nc] == white)) {
                acc += dfs(nr, nc);
            }
        }

        return acc;
    };

    vector<int> area;
    for (int row = 0; row < nrow; ++row) {
        for (int col = 0; col < ncol; ++col) {
            if (board[row][col] == white) {
                area.push_back(dfs(row, col));
            }
        }
    }

    sort(area.begin(), area.end());

    cout << area.size() << endl;
    for (const auto& a: area) {
        cout << a << ' ';
    }
    cout << endl;

    return EXIT_SUCCESS;
}

