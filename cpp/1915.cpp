#include <iostream>
#include <vector>

using namespace std;


inline int min(int a, int b) {
    return (a < b) ? a : b;
}


inline int min(int a, int b, int c) {
    return min(a, min(b, c));
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int num_row, num_col;
    cin >> num_row >> num_col;

    vector<vector<bool>> board(num_row+1, vector<bool>(num_col+1, false));
    for (int row = 1; row <= num_row; ++row) {
        string line;
        cin >> line;
        for (int col = 1; col <= num_col; ++col) {
            board[row][col] = (line[col-1] == '1');
        }
    }

    int ans = 0;
    vector<vector<int>> memo(num_row+1, vector<int>(num_col+1, 0));
    for (int row = 1; row <= num_row; ++row) {
        for (int col = 1; col <= num_col; ++col) {
            memo[row][col] = (board[row][col]) ? (min(memo[row-1][col-1], memo[row-1][col], memo[row][col-1]) + 1) : 0;
            ans = (ans < memo[row][col]) ? memo[row][col] : ans;
        }
    }
    
    cout << ans * ans << endl;

    return EXIT_SUCCESS;
}

