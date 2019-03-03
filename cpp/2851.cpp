#include <iostream>
#include <vector>

using namespace std;


inline int abs(int x) {
    return (x > 0) ? x : -x;
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    vector<int> acc(11, 0);
    for (int i = 1; i <= 10; ++i) {
        int p;
        cin >> p;
        acc[i] = acc[i-1] + p;
    }

    int ans = -1;
    int min_diff = 0x7f7f7f7f;
    for (int i = 0; i <= 10; ++i) {
        int diff = abs(acc[i] - 100);
        if (diff <= min_diff) {
            min_diff = diff;
            ans = acc[i];
        }
    }

    cout << ans << endl;

    return EXIT_SUCCESS;
}

