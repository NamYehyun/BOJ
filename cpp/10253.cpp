#include <iostream>

using namespace std;


int gcd(int a, int b) {
    return (b == 0) ? a : gcd(b, a % b);
}


int solve(int a, int b) {
    int div = gcd(a, b);

    a /= div;
    b /= div;

    if (a == 1) {
        return b;
    }

    int x = (b / a) + (b % a != 0);

    div = gcd(b, x);

    int new_a = a * (x / div) - 1 * (b / div);
    int new_b = b * (x / div);

    return solve(new_a, new_b);
}


int main(void) {
    int num_test;
    scanf("%d", &num_test);

    while (num_test--) {
        int a, b;
        scanf("%d%d", &a, &b);

        printf("%d\n", solve(a, b));
    }
    
    return EXIT_SUCCESS;
}

