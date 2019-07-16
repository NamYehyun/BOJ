#include <cmath>
#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int num_test;
    cin >> num_test;
    while (num_test--) {
        int n;
        cin >> n;

        double nn = static_cast<double>(n);
        int o = static_cast<int>(floor(nn + 0.5) - ceil(nn/2 + 0.25) + 1);
        int e = static_cast<int>(floor((nn + 1.5) / 2) - ceil((nn + 2.5) / 6) + 1);

        cout << o + e << '\n';
    }

    return EXIT_SUCCESS;
}

