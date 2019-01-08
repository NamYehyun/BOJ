#include <iostream>

using namespace std;


long long gcd(long long a, long long b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}


int main(void) {
    long long a, b;
    scanf("%lld%lld", &a, &b);
    
    long long g = gcd(a, b);
    for (long long i = 0; i < g; ++i) {
        printf("1");
    }

    printf("\n");

    return EXIT_SUCCESS;
}

