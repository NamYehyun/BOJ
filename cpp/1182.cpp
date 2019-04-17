#include <iostream>
#include <vector>

using namespace std;


int solve(int idx, vector<int>& seq, int size, int acc, int sum) {
    if (idx == size) {
        return 0;
    }

    return (acc+seq[idx] == sum) + solve(idx+1, seq, size, acc, sum) + solve(idx+1, seq, size, acc+seq[idx], sum);
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, sum;
    cin >> n >> sum;

    vector<int> seq(n);
    for (int i = 0; i < n; ++i) {
        cin >> seq[i];
    }

    cout << solve(0, seq, n, 0, sum) << endl;

    return EXIT_SUCCESS;
}

