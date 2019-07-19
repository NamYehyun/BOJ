#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    long long a, b, c;
    cin >> a >> b >> c;

    if (b >= c) {
        cout << -1 << endl;
    } else {
        cout << a / (c - b) + 1 << endl;
    }

    return EXIT_SUCCESS;
}

