#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> seq(n);
    for (int i = 0; i < n; ++i) {
        cin >> seq[i];
    }

    sort(seq.begin(), seq.end());

    long long x = 0;
    long long y = 0;
    for (int i = 0; i < n; ++i) {
        x += (i+1)*seq[i];
        y += (n-i)*seq[i];
    }

    cout << 2*(x - y) << endl;

    return EXIT_SUCCESS;
}

