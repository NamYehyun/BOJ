#include <bits/stdc++.h>

using namespace std;

#define argmin(x)	(min_element(begin(x), end(x)) - begin(x))
#define argmax(x)	(max_element(begin(x), end(x)) - begin(x))

#define get_vector(x)	do { for (auto& y: x) { cin >> y; } } while (false)
#define put_vector(x)	do { for (const auto& y: x) { cout << y << ' '; } cout << '\n'; } while (false)
#define get_matrix(x)	do { for (auto& y: x) { get_vector(y); } } while (false)
#define put_matrix(x)	do { for (const auto& y: x) { put_vector(y); } } while (false)

int main(void) {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<int> fixed(m+2, 0);
	for (int i = 1; i <= m; ++i) {
		cin >> fixed[i];
	}
	fixed[m+1] = n+1;

	vector<vector<int>> memo(n+1, vector<int>(2, -1));
	memo[1][0] = 1;
	memo[1][1] = 0;

	for (int i = 2; i <= n; ++i) {
		memo[i][0] = memo[i-1][0] + memo[i-1][1];
		memo[i][1] = memo[i-1][0];
	}

	int ans = 1;
	for (int i = 1; i <= m+1; ++i) {
		int f = fixed[i] - (fixed[i-1] + 1);
		if (f > 0) {
			ans *= (memo[f][0] + memo[f][1]);
		}
	}

	cout << ans << endl;

	return EXIT_SUCCESS;
}

