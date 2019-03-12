#include <iostream>

using namespace std;


typedef long long ll;


inline ll sq(ll x) {
    return x * x;
}


inline ll abs(ll x) {
    return (x >= 0) ? x : -x;
}


int solve(ll x1, ll y1, ll r1, ll x2, ll y2, ll r2) {
    if (x1 == x2 && y1 == y2 && r1 == r2) {
        return -1;
    }

    const int dist_sq = sq(x1 - x2) + sq(y1 - y2);

    if (sq(r1 + r2) < dist_sq || sq(r1 - r2) > dist_sq) {
        return 0;
    }

    if (sq(r1 + r2) == dist_sq || sq(r1 - r2) == dist_sq) {
        return 1;
    }

    return 2;
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        long long x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        cout << solve(x1, y1, r1, x2, y2, r2) << '\n';
    }

    return EXIT_SUCCESS;
}

