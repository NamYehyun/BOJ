#include <iostream>
#include <vector>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;

    int n_orig = n;

    vector<bool> is_prime(n+1, true);

    is_prime[0] = false;
    is_prime[1] = false;
    for (int i = 0; i <= n; ++i) {
        if (!is_prime[i]) {
            continue;
        }

        int t = 2;
        while (true) {
            if (n < t*i) {
                break;
            }

            is_prime[t*i] = false;
            ++t;
        }
    }

    vector<int> cnt(n+1, 0);
    for (int i = 0; i <= n; ++i) {
        if (!is_prime[i]) {
            continue;
        }

        while (true) {
            if (n % i != 0) {
                break;
            }

            n /= i;
            ++cnt[i];
        }
    }

    n = n_orig;

    int ans = 1;
    for (int i = 0; i <= n; ++i) {
        if (cnt[i] == 0) {
            continue;
        }

        int val = 1;
        int acc = 1;
        for (int j = 0; j < cnt[i]; ++j) {
            val *= i;
            acc += val;
        }
        
        ans *= acc;
    }

    cout << 5*ans-24 << endl;

    return EXIT_SUCCESS;
}

