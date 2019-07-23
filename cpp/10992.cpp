#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;

    for (int row = 1; row <= n-1; ++row) {
        for (int i = 0; i < n-row; ++i) {
            cout << ' ';
        }

        cout << '*';

        for (int i = 0; i < 2*row-3; ++i) {
            cout << ' ';
        }

        if (row != 1) {
            cout << '*';
        }

        cout << '\n';
    }

    for (int i = 0; i < 2*n-1; ++i) {
        cout << '*';
    }
    cout << '\n';

    return EXIT_SUCCESS;
}

