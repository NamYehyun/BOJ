#include <iostream>
#include <vector>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<bool>> mat_A(n, vector<bool>(n));
    vector<vector<bool>> mat_B(n, vector<bool>(n));
    vector<vector<bool>> mat_C(n, vector<bool>(n, false));

    /* read matrix A */
    for (int row = 0; row < n; ++row) {
        for (int col = 0; col < n; ++col) {
            int elt;
            cin >> elt;
            mat_A[row][col] = (elt == 1);
        }
    }

    /* read matrix B */
    for (int row = 0; row < n; ++row) {
        for (int col = 0; col < n; ++col) {
            int elt;
            cin >> elt;
            mat_B[row][col] = (elt == 1);
        }
    }

    /* calculate C = A x B */
    for (int i = 0; i < n; ++i) {
        for (int k = 0; k < n; ++k) {
            for (int j = 0; j < n; ++j) {
                mat_C[i][j] = mat_C[i][j] || (mat_A[i][k] && mat_B[k][j]);
            }
        }
    }

    int acc = 0;
    for (int row = 0; row < n; ++row) {
        for (int col = 0; col < n; ++col) {
            if (mat_C[row][col]) {
                ++acc;
            }
        }
    }

    cout << acc << endl;

    return EXIT_SUCCESS;
}

