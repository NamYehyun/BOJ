#include <iostream>
#include <vector>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;

    long long max_budget = 0;
    long long net_budget = 0;
    vector<long long> budget(n);
    for (int i = 0; i < n; ++i) {
        cin >> budget[i];
        max_budget = (max_budget > budget[i]) ? max_budget : budget[i];
        net_budget += budget[i];
    }

    long long net_budget_limit;
    cin >> net_budget_limit;

    if (net_budget <= net_budget_limit) {
        cout << max_budget << endl;
        return EXIT_SUCCESS;
    }
    
    int ans = 0;
    int lo = 0;
    int hi = max_budget;
    while (!(lo > hi)) {
        int mid = (lo + hi) / 2;

        long long acc = 0;
        for (const long long& b: budget) {
            acc += (b <= mid) ? b : mid;
        }

        if (acc <= net_budget_limit) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    cout << ans << endl;

    return EXIT_SUCCESS;
}

