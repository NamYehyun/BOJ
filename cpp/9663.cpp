#include <iostream>
#include <vector>

using namespace std;


bool possible(vector<int>& prev, int new_row, int new_col) {
    for (int row = 0; row < new_row; ++row) {
        int col = prev[row];

        if (new_col == col) return false;
        if (new_col == col + (new_row - row)) return false;
        if (new_col == col - (new_row - row)) return false;
    }

    return true;
}


int solve(int row, int size, vector<int>& prev) {
    if (row == size) {
        return 1;
    }

    int acc = 0;
    for (int col = 0; col < size; ++col) {
        if (possible(prev, row, col)) {
            prev[row] = col;
            acc += solve(row+1, size, prev);
        }
    }

    return acc;
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n;
    cin >> n;

    vector<int> prev(n);

    cout << solve (0, n, prev) << endl;

    return EXIT_SUCCESS;
}

