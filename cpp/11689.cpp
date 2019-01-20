/*
 * Euler's phi function:
 *   phi(n) = n PROD_{p | n} (1 - 1/p)
 */

#include <iostream>
#include <set>

using namespace std;


const int P_MAX = 1000000;


long long N;
bool is_prime[P_MAX + 1];


int main(void) {
    cin >> N;

    fill(is_prime, is_prime + P_MAX + 1, true);

    is_prime[0] = false;
    is_prime[1] = false;
    for (long long i = 2; i * i <= N; ++i) {
        if (is_prime[i]) {
            long long mul = i;
            while (true) {
                if (P_MAX < i * mul) {
                    break;
                }

                is_prime[i * mul] = false;
                ++mul;
            }
        }
    }

    long long n = N;
    set<long long> factors;

    bool fin = false;
    while (true) {
        if (fin) {
            if (n != 1) {
                factors.insert(n);
            }

            break;
        }

        fin = true;
        for (long long i = 2; i * i <= n; ++i) {
            if (is_prime[i] && n % i == 0) {
                fin = false;

                factors.insert(i);

                while (true) {
                    if (n % i != 0) {
                        break;
                    }

                    n /= i;
                }
            }
        }
    }

    for (auto p: factors) {
        N = (N / p) * (p - 1);
    }

    cout << N << endl;

    return EXIT_SUCCESS;
}

