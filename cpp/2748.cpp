#include <iostream>

using namespace std;


const int MAX_N = 90;


int main(void) {
    int n;
    scanf("%d", &n);

    long long fibo[MAX_N + 1];

    fibo[0] = 0;
    fibo[1] = 1;
    for (int i = 2; i <= n; ++i) {
        fibo[i] = fibo[i-1] + fibo[i-2];
    }

    printf("%lld\n", fibo[n]);

    return EXIT_SUCCESS;
}

