#include <cmath>
#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int num_test;
    cin >> num_test;
    while (num_test--) {
        int n;
        cin >> n;

        if (n == 1) {
            cout << 1 << '\n';
        } else {
            double ans = 0;
            for (int i = 1; i <= n; ++i) {
                ans += log10(static_cast<double>(i));
            }

            cout << static_cast<int>(ceil(ans)) << '\n';
        }
    }

    return EXIT_SUCCESS;
}

