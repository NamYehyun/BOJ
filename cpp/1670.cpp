#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

ll solve(ll n, vector<ll>& memo);

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	ll n;
	cin >> n;

	vector<ll> memo(n+1, -1);
	memo[0] = memo[2] = 1;

	cout << solve(n, memo) << endl;
	
	return EXIT_SUCCESS;
}

ll solve(ll n, vector<ll>& memo) {
	if (memo[n] != -1) {
		return memo[n];
	}

	if (n % 2 != 0) {
		return memo[n] = 0;
	}

	ll acc = 0;
	for (ll i = 0; i < n; i += 2) {
		acc += solve(i, memo) * solve(n-2-i, memo);
		acc %= 987654321;
	}

	return memo[n] = acc;
}

