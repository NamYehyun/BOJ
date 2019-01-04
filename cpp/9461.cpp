#include <iostream>

using namespace std;


const int MAX_N = 100;


int main(void) {
    long long p[MAX_N + 1];

    p[1] = 1;
    p[2] = 1;
    p[3] = 1;
    p[4] = 2;
    p[5] = 2;
    for (int i = 6; i <= MAX_N; ++i) {
        p[i] = p[i - 1] + p[i - 5];
    }
    
    int t;
    scanf("%d", &t);
    
    for (int _ = 0; _ < t; ++_) {
        int n;
        scanf("%d", &n);
        printf("%lld\n", p[n]);
    }
    
    return EXIT_SUCCESS;
}

