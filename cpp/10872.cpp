#include <iostream>

using namespace std;


long long fact(int n) {
    if (n == 0) {
        return 1;
    }

    return n * fact(n-1);
}


int main(void) {
    int n;
    scanf("%d", &n);

    printf("%lld\n", fact(n));

    return EXIT_SUCCESS;
}

