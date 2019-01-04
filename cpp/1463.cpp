#include <iostream>

using namespace std;


const int MAX_N = 1000000;
const int MAX_INT = 0x7fffffff;


int main(void) {
    int n;
    int memo[MAX_N+1];

    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
        memo[i] = MAX_INT;
    }

    memo[1] = 0;
    for (int i = 1; i <= n; ++i) {
        if ((3 * i <= n) && (memo[i] + 1 < memo[3 * i])) {
            memo[3 * i] = memo[i] + 1;
        }
        if ((2 * i <= n) && (memo[i] + 1 < memo[2 * i])) {
            memo[2 * i] = memo[i] + 1;
        }
        if ((i + 1 <= n) && (memo[i] + 1 < memo[i + 1])) {
            memo[i + 1] = memo[i] + 1;
        }
    }

    printf("%d\n", memo[n]);
    
    return EXIT_SUCCESS;
}

