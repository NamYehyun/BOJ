#include <iostream>
#include <vector>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int num_row, num_col;
    cin >> num_row >> num_col;

    vector<string> board(num_row);
    for (int row = 0; row < num_row; ++row) {
        cin >> board[row];
    }

    int max_width = 0;
    for (int row = 0; row < num_row; ++row) {
        for (int col = 0; col < num_col; ++col) {
            for (int width = max_width; (row + width < num_row) && (col + width < num_col); ++width) {
                int a = board[row][col];
                int b = board[row][col+width];
                int c = board[row+width][col];
                int d = board[row+width][col+width];

                if (a == b && b == c && c == d) {
                    max_width = width;
                }
            }
        }
    }

    cout << (max_width+1)*(max_width+1) << endl;

    return EXIT_SUCCESS;
}

