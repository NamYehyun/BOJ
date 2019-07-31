#include <iostream>
#include <vector>

using namespace std;


inline int max(int a, int b) {
    return (a > b) ? a : b;
}


inline int max(int a, int b, int c) {
    return max(a, max(b, c));
}


inline int min(int a, int b) {
    return (a < b) ? a : b;
}


inline int min(int a, int b, int c) {
    return min(a, min(b, c));
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> memo_max(3, 0);
    vector<int> memo_min(3, 0);

    for (int row = 0; row < n; ++row) {
        int a, b, c;
        cin >> a >> b >> c;

        int x = a + max(memo_max[0], memo_max[1]);
        int y = b + max(memo_max[0], memo_max[1], memo_max[2]);
        int z = c + max(memo_max[1], memo_max[2]);

        memo_max[0] = x;
        memo_max[1] = y;
        memo_max[2] = z;

        x = a + min(memo_min[0], memo_min[1]);
        y = b + min(memo_min[0], memo_min[1], memo_min[2]);
        z = c + min(memo_min[1], memo_min[2]);

        memo_min[0] = x;
        memo_min[1] = y;
        memo_min[2] = z;
    }

    cout << max(memo_max[0], memo_max[1], memo_max[2]) << ' ' << min(memo_min[0], memo_min[1], memo_min[2]) << endl;

    return EXIT_SUCCESS;
}

