#include <iostream>
#include <vector>

using namespace std;


const int drow[4] = {-1, 0, 1, 0};
const int dcol[4] = {0, 1, 0, -1};


int nrow, ncol, npos;


inline bool safe(int row, int col) {
    return (0 <= row && row < nrow) && (0 <= col && col < ncol);
}


void dfs(int row, int col, vector<vector<bool>>& field) {
    field[row][col] = false;
    
    for (int i = 0; i < 4; ++i) {
        int r = row + drow[i];
        int c = col + dcol[i];
        if (safe(r, c) && field[r][c]) {
            dfs(r, c, field);
        }
    }

    return;
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int num_test;
    cin >> num_test;

    while (num_test--) {
        cin >> nrow >> ncol >> npos;

        vector<vector<bool>> field(nrow, vector<bool>(ncol, false));
        for (int i = 0; i < npos; ++i) {
            int row, col;
            cin >> row >> col;
            field[row][col] = true;
        }

        int cnt = 0;
        for (int row = 0; row < nrow; ++row) {
            for (int col = 0; col < ncol; ++col) {
                if (field[row][col]) {
                    ++cnt;
                    dfs(row, col, field);
                }
            }
        }

        cout << cnt << '\n';
    }

    return EXIT_SUCCESS;
}

