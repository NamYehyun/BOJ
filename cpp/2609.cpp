#include <iostream>

using namespace std;


long long gcd(long long a, long long b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}


long long lcm(long long a, long long b) {
    return (a / gcd(a, b)) * b;
}


int main(void) {
    long long a, b;
    scanf("%lld%lld", &a, &b);

    printf("%lld\n%lld\n", gcd(a, b), lcm(a, b));

    return EXIT_SUCCESS;
}

