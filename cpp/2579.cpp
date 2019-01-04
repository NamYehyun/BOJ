#include <iostream>

using namespace std;


const int MAX_N = 300;


int max(int a, int b) {
    return (a > b) ? a : b;
}


int main(void) {
    int n;
    int stairs[MAX_N+1];
    int memo[MAX_N+1][2];

    scanf("%d", &n);

    stairs[0] = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", stairs + i);
    }

    memo[0][0] = 0;
    memo[0][1] = 0;

    memo[1][0] = stairs[1];
    memo[1][1] = stairs[1];

    memo[2][0] = stairs[2];
    memo[2][1] = stairs[1] + stairs[2];

    for (int i = 3; i <= n; ++i) {
        memo[i][0] = max(memo[i-2][0], memo[i-2][1]) + stairs[i];
        memo[i][1] = max(memo[i-3][0], memo[i-3][1]) + stairs[i-1] + stairs[i];
    }

    printf("%d\n", max(memo[n][0], memo[n][1]));

    return EXIT_SUCCESS;
}

