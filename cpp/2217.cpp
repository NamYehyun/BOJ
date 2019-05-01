#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


inline long long max(long long a, long long b) {
    return (a > b) ? a : b;
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;

    vector<long long> strength(n);
    for (int i = 0; i < n; ++i) {
        cin >> strength[i];
    }

    sort(strength.rbegin(), strength.rend());

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = max(ans, strength[i] * (i + 1));
    }

    cout << ans << endl;

    return EXIT_SUCCESS;
}

