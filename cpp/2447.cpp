#include <iostream>

using namespace std;


const int N_MAX = 7000;

char board[N_MAX][N_MAX];


void solve(int row, int col, int size) {
    if (size == 1) {
        board[row][col] = '*';
        return;
    }

    int sub_size = size / 3;
    solve(row+0*sub_size, col+0*sub_size, sub_size);
    solve(row+0*sub_size, col+1*sub_size, sub_size);
    solve(row+0*sub_size, col+2*sub_size, sub_size);
    solve(row+1*sub_size, col+0*sub_size, sub_size);
    solve(row+1*sub_size, col+2*sub_size, sub_size);
    solve(row+2*sub_size, col+0*sub_size, sub_size);
    solve(row+2*sub_size, col+1*sub_size, sub_size);
    solve(row+2*sub_size, col+2*sub_size, sub_size);

    return;
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int row = 0; row < n; ++row) {
        for (int col = 0; col < n; ++col) {
            board[row][col] = ' ';
        }
    }
    
    solve(0, 0, n);

    for (int row = 0; row < n; ++row) {
        for (int col = 0; col < n; ++col) {
            cout << board[row][col];
        }
        cout << '\n';
    }

    return EXIT_SUCCESS;
}

