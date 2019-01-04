#include <iostream>

using namespace std;


const int MAX_N = 500;


int max(int a, int b) {
    return (a > b) ? a : b;
}


int main(void) {
    int n;
    int triangle[MAX_N][MAX_N];

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            scanf("%d", &triangle[i][j]);
        }
    }

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (j == 0) {
                triangle[i][j] += triangle[i-1][j];
            } else if (j == i) {
                triangle[i][j] += triangle[i-1][j-1];
            } else {
                triangle[i][j] += max(triangle[i-1][j-1], triangle[i-1][j]);
            }
        }
    }

    int max = 0;
    for (int i = 0; i < n; ++i) {
        if (max < triangle[n-1][i]) {
            max = triangle[n-1][i];
        }
    }

    printf("%d\n", max);

    return EXIT_SUCCESS;
}

