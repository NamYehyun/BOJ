#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;

    for (int row = 0; row < n; ++row) {
        for (int space = 0; space < row; ++space)
            cout << ' ';

        for (int star = 0; star < 2*(n-row)-1; ++star)
            cout << '*';

        cout << '\n';
    }

    for (int row = 1; row < n; ++row) {
        for (int space = 0; space < n-row-1; ++space)
            cout << ' ';

        for (int star = 0; star < 2*row+1; ++star)
            cout << '*';
        cout << '\n';
    }

    return EXIT_SUCCESS;
}

