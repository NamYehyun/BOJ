#include <iostream>

using namespace std;


long long sum_multiple_of(int x, int bound) {
    long long n = static_cast<long long>(bound / x);
    return x * n * (n + 1) / 2;
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        cout << sum_multiple_of(3, n) + sum_multiple_of(7, n) - sum_multiple_of(21, n) << '\n';
    }

    return EXIT_SUCCESS;
}

