#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int num_test;
    cin >> num_test;
    while (num_test--) {
        int n;
        cin >> n;

        int max_n = n;
        while (n != 1) {
            n = (n % 2 == 0) ? (n / 2) : (3*n + 1);
            max_n = max(n, max_n);
        }

        cout << max_n << '\n';
    }

    return EXIT_SUCCESS;
}

