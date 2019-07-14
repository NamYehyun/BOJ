#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < n-i; ++j) {
            cout << ' ';
        }

        for (int j = 0; j < i-1; ++j) {
            cout << '*' << ' ';
        }

        cout << '*' << '\n';
    }

    return EXIT_SUCCESS;
}

