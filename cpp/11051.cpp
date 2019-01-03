#include <iostream>

using namespace std;


const int MAX_N = 1000;

int memo[MAX_N+1][MAX_N+1];


int binom(int n, int k) {
    if (memo[n][k]) {
        return memo[n][k];
    }

    if (k == 0 || n == k) {
        return memo[n][k] = 1;
    } else {
        return memo[n][k] = (binom(n-1, k-1) + binom(n-1, k)) % 10007;
    }
}


int main(void) {
    int n, k;
    scanf("%d%d", &n, &k);

    printf("%d\n", binom(n, k));

    return EXIT_SUCCESS;
}

