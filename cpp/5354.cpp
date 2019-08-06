#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int num_test;
    cin >> num_test;
    while (num_test--) {
        int n;
        cin >> n;

        for (int row = 0; row < n; ++row) {
            for (int col = 0; col < n; ++col) {
                if (row == 0 || row == n-1 || col == 0 || col == n-1) {
                    cout << '#';
                } else {
                    cout << 'J';
                }
            }
            cout << '\n';
        }
        cout << '\n';
    }

    return EXIT_SUCCESS;
}

