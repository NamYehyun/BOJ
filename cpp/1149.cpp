#include <iostream>

using namespace std;


const int MAX_N = 1000;
const int R = 0;
const int G = 1;
const int B = 2;

int cost[MAX_N][3];
int memo[MAX_N][3];


int min(int a, int b) {
    return (a < b) ? a : b;
}


int main(void) {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d", &cost[i][R], &cost[i][G], &cost[i][B]);
    }

    memo[0][R] = cost[0][R];
    memo[0][G] = cost[0][G];
    memo[0][B] = cost[0][B];
    for (int i = 1; i < n; ++i) {
        memo[i][R] = min(memo[i-1][G], memo[i-1][B]) + cost[i][R];
        memo[i][G] = min(memo[i-1][R], memo[i-1][B]) + cost[i][G];
        memo[i][B] = min(memo[i-1][R], memo[i-1][G]) + cost[i][B];
    }

    printf("%d\n", min(min(memo[n-1][R], memo[n-1][G]), memo[n-1][B]));

    return EXIT_SUCCESS;
}

