#include <iostream>

using namespace std;


const int MAX = 100;


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;

    int mat_a[MAX][MAX];
    int mat_b[MAX][MAX];
    int mat_c[MAX][MAX] = {};

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> mat_a[i][j];
        }
    }

    cin >> m >> k;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < k; ++j) {
            cin >> mat_b[i][j];
        }
    }

    for (int row = 0; row < n; ++row) {
        for (int i = 0; i < m; ++i) {
            for (int col = 0; col < k; ++col) {
                mat_c[row][col] += mat_a[row][i] * mat_b[i][col];
            }
        }
    }

    for (int row = 0; row < n; ++row) {
        for (int col = 0; col < k; ++col) {
            cout << mat_c[row][col] << ' ';
        }
        cout << '\n';
    }

    return EXIT_SUCCESS;
}

