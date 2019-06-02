#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int a, b, c;
    cin >> a >> b >> c;

    cout << (c % 2 == 0 ? a : a ^ b) << endl;

    return EXIT_SUCCESS;
}

