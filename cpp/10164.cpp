#include <iostream>
#include <vector>

using namespace std;


int solve(const int num_row, const int num_col) {
    vector<vector<int>> memo(num_row, vector<int>(num_col, 0));

    auto safe = [&num_row, &num_col](int row, int col) -> bool {
        return (0 <= row && row < num_row) && (0 <= col && col < num_col);
    };

    memo[0][0] = 1;
    for (int row = 0; row < num_row; ++row) {
        for (int col = 0; col < num_col; ++col) {
            if (safe(row-1, col)) {
                memo[row][col] += memo[row-1][col];
            }

            if (safe(row, col-1)) {
                memo[row][col] += memo[row][col-1];
            }
        }
    }

    return memo[num_row-1][num_col-1];
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int num_row, num_col, pivot;
    cin >> num_row >> num_col >> pivot;

    if (!pivot) {
        cout << solve(num_row, num_col) << endl;
    } else {
        --pivot;

        int col_pivot = pivot % num_col;
        int row_pivot = (pivot - col_pivot) / num_col;

        cout << solve(row_pivot+1, col_pivot+1) * solve(num_row-row_pivot, num_col-col_pivot) << endl;
    }

    return EXIT_SUCCESS;
}

