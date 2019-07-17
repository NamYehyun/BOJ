#include <iostream>
#include <vector>

using namespace std;


int is_palindrome(int lo, int hi, vector<int>& seq, vector<vector<int>>& memo) {
    if (memo[lo][hi] != -1) {
        return memo[lo][hi];
    }

    if (lo >= hi) {
        return memo[lo][hi] = 1;
    }

    if (seq[lo] == seq[hi]) {
        return memo[lo][hi] = is_palindrome(lo+1, hi-1, seq, memo);
    } else {
        return memo[lo][hi] = 0;
    }
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    int n;
    cin >> n;

    vector<int> seq(n);
    for (int i = 0; i < n; ++i) {
        cin >> seq[i];
    }

    int num_query;
    cin >> num_query;

    vector<vector<int>> memo(n, vector<int>(n, -1));

    while (num_query--) {
        int s, e;
        cin >> s >> e;

        cout << is_palindrome(s-1, e-1, seq, memo) << '\n';
    }

    return EXIT_SUCCESS;
}

