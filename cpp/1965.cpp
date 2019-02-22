#include <iostream>
#include <vector>

using namespace std;


int solve(int n, vector<int>& boxes, vector<int>& memo) {
    if (n < 0) {
        return 0;
    }

    if (memo[n] != -1) {
        return memo[n];
    }

    int M = 1;
    for (int i = 0; i < n; ++i) {
        int m = solve(i, boxes, memo);
        if (boxes[i] < boxes[n] && M < m + 1) {
            M = m + 1;
        }
    }

    return memo[n] = M;
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> boxes(n);
    for (int i = 0; i < n; ++i) {
        cin >> boxes[i];
    }

    vector<int> memo(n, -1);

    solve(n-1, boxes, memo);

    int ans = 0;
    for (int a: memo) {
        if (ans < a) {
            ans = a;
        }
    }

    cout << ans << endl;

    return EXIT_SUCCESS;
}

