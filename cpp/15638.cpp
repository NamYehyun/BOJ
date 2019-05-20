#include <iostream>
#include <vector>

using namespace std;


const int MAX_N = 100000;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    vector<bool> is_prime(MAX_N+1, true);

    is_prime[0] = false;
    is_prime[1] = false;
    for (int n = 2; n <= MAX_N; ++n) {
        if (!is_prime[n]) {
            continue;
        }

        int t = 2;
        while (true) {
            if (MAX_N < t*n) {
                break;
            }

            is_prime[t*n] = false;
            ++t;
        }
    }

    int n;
    cin >> n;

    cout << (is_prime[n] ? "Yes" : "No") << endl;

    return EXIT_SUCCESS;
}

