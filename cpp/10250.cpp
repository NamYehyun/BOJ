#include <iostream>

using namespace std;


int main(void) {
    int t;

    scanf("%d", &t);

    for (int _ = 0; _ < t; ++_) {
        int h, w, n;

        scanf("%d%d%d", &h, &w, &n);

        int col = (n + h - 1) / h;
        int row = n - h * (col - 1);

        printf("%d%02d\n", row, col);
    }

    return EXIT_SUCCESS;
}

