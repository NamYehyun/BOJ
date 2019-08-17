#include <iostream>

using namespace std;


long long acc(long long i, const long long k, const long long p) {
    return (i == 0) ? 0 : (k*i + p*i*i + acc(i-1, k, p));
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    long long c, k, p;
    cin >> c >> k >> p;

    cout << acc(c, k, p) << endl;

    return EXIT_SUCCESS;
}

