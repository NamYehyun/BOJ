#include <bits/stdc++.h>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;

	vector<int> weight(n);
	vector<int> value(n);
	for (int i = 0; i < n; ++i) {
		cin >> weight[i] >> value[i];
	}

	vector<vector<int>> memo(n, vector<int>(k+1));
	
	for (int w = 0; w <= k && w < weight[0]; ++w) {
		memo[0][w] = 0;
	}

	for (int w = weight[0]; w <= k; ++w) {
		memo[0][w] = value[0];
	}

	for (int i = 1; i < n; ++i) {
		for (int w = 0; w <= k && w < weight[i]; ++w) {
			memo[i][w] = memo[i-1][w];
		}

		for (int w = weight[i]; w <= k; ++w) {
			memo[i][w] = max(memo[i-1][w], memo[i-1][w-weight[i]] + value[i]);
		}
	}

	cout << memo[n-1][k] << endl;

	return EXIT_SUCCESS;
}

