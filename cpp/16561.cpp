#include <iostream>

using namespace std;


long long C(long long n, long long r) {
    return (r == 0 || r == n) ? 1 : (C(n-1, r) + C(n-1, r-1));
}


long long H(long long n, long long r) {
    return C(n+r-1, r);
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    long long n;
    cin >> n;

    n /= 3;

    cout << H(3, n-3) << endl;

    return EXIT_SUCCESS;
}

