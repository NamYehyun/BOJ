#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cout << 1;
    }

    for (int i = 0; i < n-1; ++i) {
        cout << 0;
    }

    cout << endl;

    return EXIT_SUCCESS;
}

