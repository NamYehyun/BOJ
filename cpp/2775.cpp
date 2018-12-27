#include <iostream>

using namespace std;


int apt[15][15];


int solve(int k, int n) {
    if (apt[k][n]) {
        return apt[k][n];
    } else {
        int acc = 0;
        for (int i = 1; i <= n; ++i) {
            acc += solve(k-1, i);
        }

        return apt[k][n] = acc;
    }
}


int main(void) {
    int t;

    scanf("%d", &t);

    for (int i = 1; i <= 14; ++i) {
        apt[0][i] = i;
    }

    for (int _ = 0; _ < t; ++_) {
        int k, n;

        scanf("%d%d", &k, &n);

        printf("%d\n", solve(k, n));
    }

    return EXIT_SUCCESS;
}

