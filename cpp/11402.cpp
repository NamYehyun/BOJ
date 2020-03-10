#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

ll comb(ll n, ll k, ll p, vector<vector<ll>>& memo) {
	if (memo[n][k] != -1) {
		return memo[n][k];
	}

	if (k == 0 || k == n) {
		return memo[n][k] = 1;
	}

	return memo[n][k] = (comb(n-1, k-1, p, memo) % p + comb(n-1, k, p, memo) % p) % p;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	ll n, k, p;
	cin >> n >> k >> p;

	vector<vector<ll>> memo(2001, vector<ll>(2001, -1));

	ll ans = 1;
	while (n || k) {
		if (n % p < k % p) {
			ans = 0;
			break;
		}

		ans *= comb(n % p, k % p, p, memo);
		ans %= p;

		n /= p;
		k /= p;
	}

	cout << ans << endl;

	return EXIT_SUCCESS;
}

