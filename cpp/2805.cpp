#include <iostream>
#include <vector>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    long long m;
    cin >> n >> m;

    vector<long long> height(n);
    long long max_height = 0;
    for (int i = 0; i < n; ++i) {
        cin >> height[i];
        max_height = max(height[i], max_height);
    }

    int lo = 0;
    int hi = max_height;
    while (lo <= hi) {
        int mi = (lo + hi) / 2;

        long long acc = 0;
        for (const int& h: height) {
            if (mi < h) {
                acc += h - mi;
            }
        }

        if (acc < m) {
            hi = mi - 1;
        } else {
            lo = mi + 1;
        }
    }

    cout << hi << endl;

    return EXIT_SUCCESS;
}

