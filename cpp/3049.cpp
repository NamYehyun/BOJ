#include <iostream>

using namespace std;


long long comb(long long n, long long r) {
    if (r == 0 || r == n) {
        return 1;
    }

    return comb(n-1, r-1) + comb(n-1, r);
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    long long n;
    cin >> n;

    cout << comb(n, 4) << endl;

    return EXIT_SUCCESS;
}

