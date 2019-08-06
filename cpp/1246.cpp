#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<long long> seq(m);
    for (int i = 0; i < m; ++i) {
        cin >> seq[i];
    }

    sort(seq.rbegin(), seq.rend());

    int p = min(n, m);

    int price = 0;
    int max_profit = 0;
    for (int i = 1; i <= p; ++i) {
        int profit = i * seq[i-1];
        if (max_profit < profit) {
            max_profit = profit;
            price = seq[i-1];
        }
    }
    
    cout << price << ' ' << max_profit << endl;

    return EXIT_SUCCESS;
}

