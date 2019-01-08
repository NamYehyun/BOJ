#include <iostream>

using namespace std;


int gcd(int a, int b) {
    return (b == 0) ? a : gcd(b, a % b);
}


int main(void) {
    int n;
    scanf("%d", &n);

    int pivot;
    scanf("%d", &pivot);

    for (int i = 1; i < n; ++i) {
        int ring;
        scanf("%d", &ring);

        int div = gcd(pivot, ring);

        printf("%d/%d\n", pivot / div, ring / div);
    }

    return EXIT_SUCCESS;
}

