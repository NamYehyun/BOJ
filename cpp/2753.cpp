#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;

    if (n % 400 == 0 || (n % 4 == 0 && n % 100 != 0)) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }

    return EXIT_SUCCESS;
}

