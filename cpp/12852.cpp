#include <iostream>
#include <queue>
#include <vector>

using namespace std;

using ll = long long;

const ll INF = 0x7f7f7f7f7f7f7f7f;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	ll n;
	cin >> n;

	vector<ll> cnt(n+1, INF);
	vector<int> cmd(n+1, -1);
	queue<ll> queue;

	cnt[n] = 0;
	cmd[n] = 0;
	queue.push(n);

	while (!queue.empty()) {
		ll curr = queue.front(); queue.pop();

		if (curr % 3 == 0 && cnt[curr/3] > cnt[curr] + 1) {
			cnt[curr/3] = cnt[curr] + 1;
			cmd[curr/3] = 1;
			queue.push(curr/3);
		}

		if (curr % 2 == 0 && cnt[curr/2] > cnt[curr] + 1) {
			cnt[curr/2] = cnt[curr] + 1;
			cmd[curr/2] = 2;
			queue.push(curr/2);
		}

		if (curr > 1 && cnt[curr-1] > cnt[curr] + 1) {
			cnt[curr-1] = cnt[curr] + 1;
			cmd[curr-1] = 3;
			queue.push(curr-1);
		}
	}

	cout << cnt[1] << '\n';
	
	vector<ll> path;
	path.reserve(cnt[1] + 1);

	int curr = 1;
	path.emplace_back(1);

	for (int i = 0; i < cnt[1]; ++i) {
		if (cmd[curr] == 1) {
			curr *= 3;
		} else if (cmd[curr] == 2) {
			curr *= 2;
		} else if (cmd[curr] == 3) {
			curr += 1;
		}

		path.emplace_back(curr);
	}

	for (int i = cnt[1]; i >= 0; --i) {
		cout << path[i] << ' ';
	}
	cout << '\n';


	return EXIT_SUCCESS;
}

