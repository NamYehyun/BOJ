#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            cout << '*';
        }
        cout << '\n';
    }

    for (int i = n-1; i >= 1; --i) {
        for (int j = 0; j < i; ++j) {
            cout << '*';
        }
        cout << '\n';
    }

    return EXIT_SUCCESS;
}

