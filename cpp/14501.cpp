#include <iostream>
#include <vector>

using namespace std;


int solve(int curr, int end, vector<int>& cost, vector<int>& value, vector<int>& memo) {
    if (end < curr) {
        return 0;
    }

    if (memo[curr] != -1) {
        return memo[curr];
    }

    int max_value = (end < curr+cost[curr]-1) ? 0 : (value[curr] + solve(curr+cost[curr], end, cost, value, memo));
    if (max_value < solve(curr+1, end, cost, value, memo)) {
        max_value = solve(curr+1, end, cost, value, memo);
    }

    return memo[curr] = max_value;
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> cost(n+1);
    vector<int> value(n+1);
    for (int day = 1; day <= n; ++day) {
        cin >> cost[day] >> value[day];
    }

    vector<int> memo(n+1, -1);
    cout << solve(1, n, cost, value, memo) << endl;

    return EXIT_SUCCESS;
}

