#include <iostream>

using namespace std;


inline long long min(long long x, long long y) {
    return (x < y) ? x : y;
}

inline long long max(long long x, long long y) {
    return (x > y) ? x : y;
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    long long a, b, c, d, p;
    cin >> a >> b >> c >> d >> p;

    long long x = p*a;
    long long y = b + max(0, p-c)*d;

    cout << min(x, y) << endl;

    return EXIT_SUCCESS;
}

