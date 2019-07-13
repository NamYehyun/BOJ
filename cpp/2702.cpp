#include <iostream>

using namespace std;


int gcd(int a, int b) {
    return (b == 0) ? a : gcd(b, a % b);
}


int lcm(int a, int b) {
    int d = gcd(a, b);
    return a * b / d;
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int num_test;
    cin >> num_test;
    while (num_test--) {
        int a, b;
        cin >> a >> b;
        cout << lcm(a, b) << ' ' << gcd(a, b) << '\n';
    }

    return EXIT_SUCCESS;
}

