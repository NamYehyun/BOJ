#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int num_test;
    cin >> num_test;
    while (num_test--) {
        int n, m;
        cin >> n >> m;

        int cnt = 0;
        for (int b = 2; b < n; ++b) {
            for (int a = 1; a < b; ++a) {
                if ((a*a + b*b + m) % (a*b) == 0) {
                    ++cnt;
                }
            }
        }

        cout << cnt << '\n';
    }

    return EXIT_SUCCESS;
}

