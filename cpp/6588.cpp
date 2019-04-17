#include <iostream>
#include <vector>

using namespace std;


const int limit = 1000000;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    vector<bool> is_prime(limit+1, true);
    
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= limit; ++i) {
        if (!is_prime[i]) {
            continue;
        }

        int mul = 2;
        while (true) {
            int next = i * mul;
            if (limit < next) {
                break;
            }

            is_prime[next] = false;

            ++mul;
        }
    }

    while (true) {
        int n;
        cin >> n;

        if (!n) {
            break;
        }

        for (int a = 3; a <= limit; ++a) {
            if (!is_prime[a]) {
                continue;
            }

            int b = n - a;
            if (is_prime[b]) {
                cout << n << " = " << a << " + " << b << "\n";
                break;
            }
        }
    }


    return EXIT_SUCCESS;
}

