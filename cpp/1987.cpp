#include <iostream>
#include <vector>

using namespace std;


const int drow[4] = {-1, 0, 1, 0};
const int dcol[4] = {0, 1, 0, -1};


int nrow, ncol;


inline int index(char c) {
    return c - 'A';
}


inline bool safe(int row, int col) {
    return (0 <= row && row < nrow) && (0 <= col && col < ncol);
}


int dfs(int row, int col, vector<string>& board, vector<bool>& visited) {
    char curr = board[row][col];
    visited[index(curr)] = true;

    int sub_max = 0;
    for (int i = 0; i < 4; ++i) {
        int r = row + drow[i];
        int c = col + dcol[i];
        if (safe(r, c) && !visited[index(board[r][c])]) {
            int tmp = dfs(r, c, board, visited);
            if (sub_max < tmp) {
                sub_max = tmp;
            }
        }
    }

    visited[index(curr)] = false; 
    return sub_max + 1;
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> nrow >> ncol;

    vector<string> board(nrow);
    for (int row = 0; row < nrow; ++row) {
        cin >> board[row];
    }

    vector<bool> visited(26, false);
    cout << dfs(0, 0, board, visited) << endl;
    
    return EXIT_SUCCESS;
}

