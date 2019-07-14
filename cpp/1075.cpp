#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    long long n, f;
    cin >> n >> f;

    n = (n / 100) * 100;
    int ans = 0;
    for (ans = 0; ans < f; ++ans) {
        if ((n + ans) % f == 0) {
            break;
        }
    }

    if (ans < 10) {
        cout << 0;
    }
    cout << ans << endl;

    return EXIT_SUCCESS;
}

