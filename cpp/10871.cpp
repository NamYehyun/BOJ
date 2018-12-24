#include <iostream>

using namespace std;


int main(void) {
    int n, x;

    scanf("%d%d", &n, &x);

    for (int _ = 0; _ < n; ++_) {
        int a;
        scanf("%d", &a);
        if (a < x) {
            printf("%d ", a);
        }
    }

    printf("\n");

    return EXIT_SUCCESS;
}

