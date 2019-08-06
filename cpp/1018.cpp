#include <iostream>
#include <vector>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int nrow, ncol;
    cin >> nrow >> ncol;

    vector<string> board(nrow);
    for (int row = 0; row < nrow; ++row) {
        cin >> board[row];
    }

    int min_diff = 65;
    for (int row = 0; row + 7 < nrow; ++row) {
        for (int col = 0; col + 7 < ncol; ++col) {
            int case_w = 0;
            int case_b = 0;
            for (int dr = 0; dr <= 7; ++dr) {
                for (int dc = 0; dc <= 7; ++dc) {
                    if ((dr+dc) % 2 == 0) {
                        if (board[row+dr][col+dc] == 'B') {
                            ++case_w;
                        } else {
                            ++case_b;
                        }
                    } else {
                        if (board[row+dr][col+dc] == 'W') {
                            ++case_w;
                        } else {
                            ++case_b;
                        }
                    }
                }
            }
            int diff = min(case_w, case_b);
            min_diff = min(diff, min_diff);
        }
    }

    cout << min_diff << endl;

    return EXIT_SUCCESS;
}

