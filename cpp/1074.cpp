#include <iostream>

using namespace std;


int pow2(int n) {
    if (n == 0) {
        return 1;
    }

    int sqrt = pow2(n / 2);
    return sqrt * sqrt * (n % 2 == 0 ? 1 : 2);
}


int solve(int size, int r, int c) {
    if (size == 2) {
        return 2 * r + c;
    }

    int half = size / 2;
    if (r < half && c < half) {
        return solve(half, r, c);
    } else if (r < half && c >= half) {
        return solve(half, r, c-half) + 1*half*half;
    } else if (r >= half && c < half) {
        return solve(half, r-half, c) + 2*half*half;
    } else if (r >= half && c >= half) {
        return solve(half, r-half, c-half) + 3*half*half;
    } else {
        /* impossible */
        return -1;
    }
}


int main(void) {
    int n, r, c;
    scanf("%d%d%d", &n, &r, &c);

    printf("%d\n", solve(pow2(n), r, c));

    return EXIT_SUCCESS;
}

