#include <iostream>
#include <vector>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> height(n);
    for (int i = 0; i < n; ++i) {
        cin >> height[i];
    }

    int max_diff = 0;
    int lo = height[0];
    int hi = height[0];
    for (int i = 1; i < n; ++i) {
        if (height[i] > height[i-1]) {
            hi = height[i];
        } else {
            int diff = hi - lo;
            max_diff = max(diff, max_diff);

            lo = hi = height[i];
        }
    }

    int diff = hi - lo;
    max_diff = max(diff, max_diff);

    cout << max_diff << endl;

    return EXIT_SUCCESS;
}

