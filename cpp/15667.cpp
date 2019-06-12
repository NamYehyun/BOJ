#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int x;
    cin >> x;

    int lo = 0;
    int hi = 111;
    int ans = -1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (1 + mid + mid*mid == x) {
            ans = mid;
            break;
        } else if (1 + mid + mid*mid < x) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    cout << ans << endl;

    return EXIT_SUCCESS;
}

