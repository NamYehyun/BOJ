#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> cost(n);
    for (int i = 0; i < n; ++i) {
        cin >> cost[i];
    }

    sort(cost.begin(), cost.end());

    long long acc = 0;
    for (int i = 0; i < n; ++i) {
        acc += static_cast<long long>(cost[i] * (n-i));
    }

    cout << acc << endl;

    return EXIT_SUCCESS;
}

