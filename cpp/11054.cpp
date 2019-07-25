#include <algorithm>
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

    vector<int> memo1(n, 0);
    for (int i = 0; i < n; ++i) {
        int max_prev = 0;
        for (int j = 0; j < i; ++j) {
            int prev = (seq[j] < seq[i]) ? memo1[j] : 0;
            max_prev = max(prev, max_prev);
        }
        memo1[i] = max_prev + 1;
    }

    reverse(seq.begin(), seq.end());

    vector<int> memo2(n, 0);
    for (int i = 0; i < n; ++i) {
        int max_prev = 0;
        for (int j = 0; j < i; ++j) {
            int prev = (seq[j] < seq[i]) ? memo2[j] : 0;
            max_prev = max(prev, max_prev);
        }
        memo2[i] = max_prev + 1;
    }

    int max_memo = 0;
    for (int i = 0; i < n; ++i) {
        int memo = memo1[i] + memo2[n-i-1] - 1;
        max_memo = max(memo, max_memo);
    }

    cout << max_memo << endl;
    
    return EXIT_SUCCESS;
}

