#include <iostream>

using namespace std;


const int MAX_N = 3 * 1024 + 10;

char board[MAX_N][2 * MAX_N];


void make_triangle(int size, int apex_row, int apex_col) {
    if (size == 3) {
        board[apex_row][apex_col] = '*';
        board[apex_row+1][apex_col-1] = board[apex_row+1][apex_col+1] = '*';
        for (int i = -2; i <= 2; ++i) {
            board[apex_row+2][apex_col+i] = '*';
        }
    } else {
        make_triangle(size/2, apex_row, apex_col);
        make_triangle(size/2, apex_row + size/2, apex_col - size/2);
        make_triangle(size/2, apex_row + size/2, apex_col + size/2);
    }
}


int main(void) {
    int n;
    scanf("%d", &n);

    for (int row = 0; row < MAX_N; ++row) {
        for (int col = 0; col < 2*MAX_N; ++col) {
            board[row][col] = ' ';
        }
    }

    make_triangle(n, 0, n);

    for (int row = 0; row < n; ++row) {
        for (int col = 1; col <= 2 * n; ++col) {
            printf("%c", board[row][col]);
        }
        printf("\n");
    }

    return EXIT_SUCCESS;
}

