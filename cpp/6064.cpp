#include <iostream>

using namespace std;


int gcd(int a, int b) {
    return (b == 0) ? a : gcd(b, a % b);
}


int lcm(int a, int b) {
    return a * b / gcd(a, b);
}


int main(void) {
    int t;
    
    scanf("%d", &t);

    for (int _ = 0; _ < t; ++_) {
        int M, N, m, n;

        scanf("%d%d%d%d", &M, &N, &m, &n);

        if (N < M) {
            int tmp;

            tmp = M;
            M = N;
            N = tmp;

            tmp = m;
            m = n;
            n = tmp;
        }

        /* solve M * x + m = N * y + n */
        int ans = -1;
        int bound = lcm(M, N) / N;
        for (int y = 0; y < bound; ++y) {
            int x = (N * y + n - m) / M;
            if (M * x + m == N * y + n) {
                ans = M * x + m;
            }
        }

        printf("%d\n", ans);
    }

    return EXIT_SUCCESS;
}

