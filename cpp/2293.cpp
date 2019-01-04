#include <iostream>

using namespace std;


const int MAX_N = 100;
const int MAX_K = 10000;


int main(void) {
    int n, k;
    int coin[MAX_N];

    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", coin + i);
    }

    int count[MAX_K + 1] = {};

    count[0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int sum = 0; sum <= k; ++sum) {
            if (sum + coin[i] <= k) {
                count[sum + coin[i]] += count[sum];
            }
        }
    }

    printf("%d\n", count[k]);

    return EXIT_SUCCESS;
}

