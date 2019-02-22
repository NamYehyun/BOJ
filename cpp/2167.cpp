#include <iostream>
#include <vector>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int nrow, ncol;
    cin >> nrow >> ncol;

    vector<vector<int>> matrix(nrow+1, vector<int>(ncol+1, 0));
    for (int row = 1; row <= nrow; ++row) {
        for (int col = 1; col <= ncol; ++col) {
            cin >> matrix[row][col];
        }
    }

    vector<vector<int>> acc(nrow+1, vector<int>(ncol+1, 0));
    for (int row = 1; row <= nrow; ++row) {
        for (int col = 1; col <= ncol; ++col) {
            acc[row][col] = acc[row-1][col] + acc[row][col-1] - acc[row-1][col-1] + matrix[row][col];
        }
    }

    int ntest;
    cin >> ntest;
    
    while (ntest--) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;

        cout << acc[r2][c2] - acc[r2][c1-1] - acc[r1-1][c2] + acc[r1-1][c1-1] << '\n';
    }
    
    return EXIT_SUCCESS;
}

