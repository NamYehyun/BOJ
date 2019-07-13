#include <iostream>

using namespace std;


int gcd(int a, int b) {
    return (b == 0) ? a : gcd(b, a % b);
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int a, b;
    char colon;
    cin >> a >> colon >> b;

    int d = gcd(a, b);
    cout << a / d << colon << b / d << endl;

    return EXIT_SUCCESS;
}

