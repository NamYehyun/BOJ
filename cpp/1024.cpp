#include <iostream>

using namespace std;


int sigma(int from, int to) {
    int acc = 0;
    for (int i = from; i <= to; ++i) {
        acc += i;
    }

    return acc;
}


int main(void) {
    int n, l;
    scanf("%d%d", &n, &l);

    for (int len = l; len <= 100; ++len) {
        int pivot = n / len;

        int from = pivot - (len / 2) + (len % 2 == 0);
        int to = pivot + (len / 2);

        if (from < 0) {
            continue;
        }

        if (sigma(from, to) == n) {
            for (int i = from; i <= to; ++i) {
                printf("%d ", i);
            }
            printf("\n");
            return EXIT_SUCCESS;
        }
    }

    printf("-1\n");

    return EXIT_SUCCESS;
}

