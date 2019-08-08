#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int s, k;
    cin >> s >> k;

    int x = s / k;
    int y = s % k;

    unsigned long long ans = 1;
    for (int i = 0; i < y; ++i) {
        ans *= (x + 1);
    }

    for (int i = y; i < k; ++i) {
        ans *= x;
    }

    cout << ans << endl;

    return EXIT_SUCCESS;
}

