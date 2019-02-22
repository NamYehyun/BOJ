#include <iostream>
#include <vector>

using namespace std;


int max(int a, int b) {
    return (a > b) ? a : b;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<vector<int>> value(2, vector<int>(n+1));
        for (int row = 0; row < 2; ++row) {
            for (int col = 1; col <= n; ++col) {
                cin >> value[row][col];
            }
        }

        vector<vector<int>> memo(2, vector<int>(n+1, 0));
        
        memo[0][1] = value[0][1];
        memo[1][1] = value[1][1];
        for (int col = 2; col <= n; ++col) {
            memo[0][col] = max(memo[1][col-2], memo[1][col-1]) + value[0][col];
            memo[1][col] = max(memo[0][col-2], memo[0][col-1]) + value[1][col];
        }

        cout << max(memo[0][n], memo[1][n]) << '\n';
    }

    return EXIT_SUCCESS;
}

