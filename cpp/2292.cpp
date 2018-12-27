#include <iostream>

using namespace std;


/*
 * f(x) = 1 + 3 * x * (x + 1)
 */
int f(int x) {
    if (x < 0) {
        return -1;
    } else {
        return 1 + 3 * x * (x + 1);
    }
}


/*
 * Solve f(i-1) < n <= f(i)
 */
int solve(int n, int from, int to) {
    int mid = (from + to)/2;

    if (f(mid-1) < n && n <= f(mid)) {
        return mid;
    } else if (n <= f(mid-1)) {
        return solve(n, from, mid);
    } else if (f(mid) < n) {
        return solve(n, mid+1, to);
    } else {
        // impossible
        return -1;
    }
}


int main(void) {
    int n;

    scanf("%d", &n);
    printf("%d\n", solve(n, 0, 20000) + 1);

    return EXIT_SUCCESS;
}

