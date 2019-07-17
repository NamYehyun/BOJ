#include <iostream>

using namespace std;


long long gcd(long long a, long long b) {
    return (b == 0) ? a : gcd(b, a % b);
}


long long lcm(long long a, long long b) {
    long long d = gcd(a, b);
    return (a / d) * b;
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int num_test;
    cin >> num_test;
    while (num_test--) {
        long long a, b;
        cin >> a >> b;

        cout << lcm(a, b) << '\n';
    }

    return EXIT_SUCCESS;
}

