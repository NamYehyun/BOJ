#include <iostream>

using namespace std;


const int MAX_N = 100000;


int main(void) {
    int n;
    int num[MAX_N];
    
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", num + i);
    }

    int acc = 0;
    int sum[MAX_N];
    for (int i = 0; i < n; ++i) {
        acc += num[i];
        sum[i] = acc;

        if (acc < 0) {
            acc = 0;
        }
    }

    int max = -1000;
    for (int i = 0; i < n; ++i) {
        if (max < sum[i]) {
            max = sum[i];
        }
    }

    printf("%d\n", max);

    return EXIT_SUCCESS;
}

