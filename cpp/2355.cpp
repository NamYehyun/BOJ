#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    long long a, b;
    cin >> a >> b;

    if (a > b) {
        int tmp = a;
        a = b;
        b = tmp;
    }

    cout << (a + b) * (b - a + 1) / 2 << endl;

    return EXIT_SUCCESS;
}

