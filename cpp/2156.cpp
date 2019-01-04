#include <iostream>

using namespace std;


const int MAX_N = 10000;


int max(int a, int b) {
    return (a > b) ? a : b;
}


int main(void) {
    int n;
    int vine[MAX_N + 1];

    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", vine + i);
    }

    int memo[MAX_N + 1][2] = {};

    memo[1][0] = vine[1];
    memo[1][1] = vine[1];

    memo[2][0] = vine[2];
    memo[2][1] = vine[1] + vine[2];
    
    for (int i = 3; i <= n; ++i) {
        memo[i][0] = max(memo[i-2][0], memo[i-2][1]) + vine[i];
        memo[i][1] = max(max(memo[i-3][0], memo[i-3][1]) + vine[i-1] + vine[i], max(memo[i-1][0], memo[i-1][1]));
    }

    printf("%d\n", max(memo[n][0], memo[n][1]));

    return EXIT_SUCCESS;
}

