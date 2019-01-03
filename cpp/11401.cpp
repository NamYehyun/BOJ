#include <iostream>

using namespace std;


const int MAX_N = 4000000;
const int DIV = 1000000007;


/*
long long fact(long long n) {
    if (n == 0) {
        return 1;
    } else {
        return n * fact(n-1);
    }
}


long long power(long long a, long long x) {
    if (x == 0) {
        return 1;
    }

    if (x % 2 == 0) {
        long long sqrt = power(a, x/2);
        return (sqrt * sqrt) % DIV;
    } else {
        long long sqrt = power(a, x/2);
        return (((sqrt * sqrt) % DIV) * a) % DIV;
    }
}


long long binom(long long n, long long k) {
    if (k == 0 || k == n) {
        return 1;
    } else {
        return (((fact(n) * power(fact(k), DIV-2)) % DIV) * power(fact(n-k), DIV-2)) % DIV;
    }
}
*/

long long fact[MAX_N+1];


long long power(long long a, long long x) {
    long long ans = 1;
    while (true) {
        if (x == 0) {
            break;
        }

        if (x % 2 != 0) {
            ans = (ans * a) % DIV;
        }
        
        a = (a * a) % DIV;
        x = x / 2;
    }

    return ans;
}


int main(void) {
    long long n, k;
    scanf("%lld%lld", &n, &k);

    /* printf("%lld\n", binom(n, k)); */

    fact[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fact[i] = (i * fact[i-1]) % DIV;
    }

    long long inv1 = power(fact[k], DIV-2);
    long long inv2 = power(fact[n-k], DIV-2);

    printf("%lld\n", (((fact[n] * inv1) % DIV) * inv2) % DIV);
    
    return EXIT_SUCCESS;
}

