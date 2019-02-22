#include <iostream>
#include <vector>

using namespace std;


int nrow, ncol;


inline bool safe(int row, int col) {
    return (0 <= row && row < nrow) && (0 <= col && col < ncol);
}


inline int max(int a, int b) {
    return (a > b) ? a : b;
}


inline int max(int a, int b, int c) {
    return max(a, max(b, c));
}


int solve(int row, int col, vector<vector<int>>& maze, vector<vector<int>>& memo) {
    if (!safe(row, col)) {
        return 0;
    }

    if (memo[row][col] != -1) {
        return memo[row][col];
    }

    int a = solve(row-1, col, maze, memo);
    int b = solve(row, col-1, maze, memo);
    int c = solve(row-1, col-1, maze, memo);

    return memo[row][col] = max(a, b, c) + maze[row][col];
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> nrow >> ncol;

    vector<vector<int>> maze(nrow, vector<int>(ncol));
    for (int row = 0; row < nrow; ++row) {
        for (int col = 0; col < ncol; ++col) {
            cin >> maze[row][col];
        }
    }

    vector<vector<int>> memo(nrow, vector<int>(ncol, -1));

    cout << solve(nrow-1, ncol-1, maze, memo) << endl;

    return EXIT_SUCCESS;
}

