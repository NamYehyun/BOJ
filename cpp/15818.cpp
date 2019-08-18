#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    long long n, m;
    cin >> n >> m;

    long long ans;
    cin >> ans;

    ans %= m;

    for (int i = 1; i < n; ++i) {
        long long num;
        cin >> num;

        ans = ((ans % m) * (num % m)) % m;
    }

    cout << ans << endl;

    return EXIT_SUCCESS;
}

