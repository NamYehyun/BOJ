#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;

    for (int row = 1; row <= n-1; ++row) {
        for (int star = 1; star <= row; ++star) cout << '*';
        for (int space = 1; space <= n-row; ++space) cout << ' ';
        for (int space = 1; space <= n-row; ++space) cout << ' ';
        for (int star = 1; star <= row; ++star) cout << '*';
        cout << endl;
    }

    for (int star = 1; star <= n; ++star) cout << '*';
    for (int star = 1; star <= n; ++star) cout << '*';
    cout << endl;

    for (int row = n-1; row >= 1; --row) {
        for (int star = 1; star <= row; ++star) cout << '*';
        for (int space = 1; space <= n-row; ++space) cout << ' ';
        for (int space = 1; space <= n-row; ++space) cout << ' ';
        for (int star = 1; star <= row; ++star) cout << '*';
        cout << endl;
    }

    return EXIT_SUCCESS;
}

