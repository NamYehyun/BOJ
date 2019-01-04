#include <iostream>

using namespace std;


const int MAX = 500;
const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, -1, 0, 1};

int n, m;
long long map[MAX][MAX];
long long memo[MAX][MAX];


bool safe(int row, int col) {
    return (0 <= row && row < n) && (0 <= col && col < m);
}


long long solve(int r, int c) {
    if (memo[r][c] != -1) {
        return memo[r][c];
    }

    long long acc = 0;
    for (int i = 0; i < 4; ++i) {
        int row = r + dr[i];
        int col = c + dc[i];
        if (safe(row, col) && (map[r][c] < map[row][col])) {
            acc += solve(row, col);
        }
    }

    return memo[r][c] = acc;
}


int main(void) {
    scanf("%d%d", &n, &m);
    for (int row = 0; row < n; ++row) {
        for (int col = 0; col < m; ++col) {
            scanf("%lld", &map[row][col]);
            memo[row][col] = -1;
        }
    }

    memo[0][0] = 1;

    printf("%lld\n", solve(n-1, m-1));
    
    return EXIT_SUCCESS;
}

