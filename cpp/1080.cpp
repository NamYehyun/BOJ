#include <iostream>
#include <vector>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int num_row, num_col;
    cin >> num_row >> num_col;

    vector<string> mat1(num_row);
    for (int row = 0; row < num_row; ++row) {
        cin >> mat1[row];
    }

    vector<string> mat2(num_row);
    for (int row = 0; row < num_row; ++row) {
        cin >> mat2[row];
    }

    int cnt = 0;
    const int drow[9] = {0, 0, 0, 1, 1, 1, 2, 2, 2};
    const int dcol[9] = {0, 1, 2, 0, 1, 2, 0, 1, 2};
    for (int row = 0; row < num_row - 2; ++row) {
        for (int col = 0; col < num_col - 2; ++col) {
            if (mat1[row][col] != mat2[row][col]) {
                for (int i = 0; i < 9; ++i) {
                    int nrow = row + drow[i];
                    int ncol = col + dcol[i];
                    mat1[nrow][ncol] = (mat1[nrow][ncol] == '0') ? '1' : '0';
                }
                ++cnt;
            }
        }
    }

    bool identical = true;
    for (int row = 0; row < num_row; ++row) {
        for (int col = 0; col < num_col; ++col) {
            if (mat1[row][col] != mat2[row][col]) {
                identical = false;
            }
        }
    }

    cout << (identical ? cnt : -1) << endl; 

    return EXIT_SUCCESS;
}

