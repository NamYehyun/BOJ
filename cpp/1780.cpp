#include <iostream>

using namespace std;


const int N_MAX = 2187;


class Count {
public:
    int minus;
    int zero;
    int plus;

    Count() {
        minus = 0;
        zero  = 0;
        plus  = 0;
    }

    Count(int m, int z, int p) {
        minus = m;
        zero  = z;
        plus  = p;
    }

    Count& operator+=(const Count& c) {
        minus += c.minus;
        zero  += c.zero;
        plus  += c.plus;

        return *this;
    }

    void print(void) {
        printf("%d\n%d\n%d\n", minus, zero, plus);
    }
};


bool is_uniform(int** board, int size) {
    if (size == 1) {
        return true;
    }

    int rep = board[0][0];
    for (int row = 0; row < size; ++row) {
        for (int col = 0; col < size; ++col) {
            if (board[row][col] != rep) {
                return false;
            }
        }
    }

    return true;
}


Count solve(int** board, int size) {
    if (is_uniform(board, size)) {
        int val = board[0][0];
        if (val == -1) {
            return Count(1, 0, 0);
        } else if (val == 0) {
            return Count(0, 1, 0);
        } else if (val == 1) {
            return Count(0, 0, 1);
        }
    }

    Count count;

    int sub_size = size / 3;
    for (int row = 0; row < size; row += sub_size) {
        for (int col = 0; col < size; col += sub_size) {
            int** sub_board = new int*[sub_size];
            for (int i = 0; i < sub_size; ++i) {
                sub_board[i] = new int[sub_size];
            }

            for (int sub_row = 0; sub_row < sub_size; ++sub_row) {
                for (int sub_col = 0; sub_col < sub_size; ++sub_col) {
                    sub_board[sub_row][sub_col] = board[row + sub_row][col + sub_col];
                }
            }

            count += solve(sub_board, sub_size);

            for (int i = 0; i < sub_size; ++i) {
                delete[] sub_board[i];
            }
            delete[] sub_board;
        }
    }

    return count;
}


int main(void) {
    int n;
    scanf("%d", &n);

    int** board = new int*[n];
    for (int i = 0; i < n; ++i) {
        board[i] = new int[n];
    }

    for (int row = 0; row < n; ++row) {
        for (int col = 0; col < n; ++col) {
            scanf("%d", &board[row][col]);
        }
    }

    solve(board, n).print();

    for (int i = 0; i < n; ++i) {
        delete[] board[i];
    }
    delete[] board;

    return EXIT_SUCCESS;
}

