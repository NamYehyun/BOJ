#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;

    int x, y, z;

    x = 0;
    y = 1;
    for (int i = 0; i < n; ++i) {
        z = x + y;

        x = y;
        y = z;
    }

    cout << x << endl;

    return EXIT_SUCCESS;
}

