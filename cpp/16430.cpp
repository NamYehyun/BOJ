#include <iostream>

using namespace std;


int gcd(int x, int y) {
    return (y == 0) ? x : gcd(y, x % y);
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int a, b;
    cin >> a >> b;

    int c = b - a;
    int d = gcd(c, b);

    cout << c/d << ' ' << b/d << endl;

    return EXIT_SUCCESS;
}

