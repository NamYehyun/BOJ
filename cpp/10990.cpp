#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;

    for (int s = 1; s <= n; ++s) {
        for (int b = 0; b < n-s; ++b) {
            cout << ' ';
        }

        cout << '*';

        for (int b = 0; b < 2*s-3; ++b) {
            cout << ' ';
        }

        if (s != 1) {
            cout << '*';
        }

        cout << '\n';
    }

    return EXIT_SUCCESS;
}

