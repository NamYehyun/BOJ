#include <iostream>
#include <vector>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> seq(n);
    for (int i = 0; i < n; ++i) {
        cin >> seq[i];
    }

    int max_memo = 0;
    vector<int> memo(n, 0);
    for (int i = 0; i < n; ++i) {
        int max_prev = 0;
        for (int j = 0; j < i; ++j) {
            int prev = (seq[j] < seq[i]) ? memo[j] : 0;
            max_prev = max(prev, max_prev);
        }

        memo[i] = max_prev + seq[i];
        max_memo = max(memo[i], max_memo);
    }

    cout << max_memo << endl;

    return EXIT_SUCCESS;
}

