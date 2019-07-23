#include <iostream>
#include <vector>

using namespace std;


inline long long gcd(long long a, long long b) {
    return (b == 0) ? a : gcd(b, a % b);
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int num_test;
    cin >> num_test;
    while (num_test--) {
        int n;
        cin >> n;

        vector<long long> seq(n);
        for (int i = 0; i < n; ++i) {
            cin >> seq[i];
        }

        long long acc = 0;
        for (int i = 0; i < n-1; ++i) {
            for (int j = i+1; j < n; ++j) {
                acc += gcd(seq[i], seq[j]);
            }
        }

        cout << acc << '\n';
    }

    return EXIT_SUCCESS;
}

