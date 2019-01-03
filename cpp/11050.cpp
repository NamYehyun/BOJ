#include <iostream>

using namespace std;


int binom(int n, int k) {
    if (k == 0 || n == k) {
        return 1;
    } else {
        return binom(n-1, k-1) + binom(n-1, k);
    }
}


int main(void) {
    int n, k;
    scanf("%d%d", &n, &k);

    printf("%d\n", binom(n, k));

    return EXIT_SUCCESS;
}

