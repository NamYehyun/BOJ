#include <iostream>
#include <queue>
#include <vector>

using namespace std;

using ll = long long;

const ll INF = 0x7f7f7f7f7f7f7f7f;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	ll f, s, g, u, d;
	cin >> f >> s >> g >> u >> d;

	vector<ll> dist(f+1, INF);
	queue<ll> queue;

	dist[s] = 0;
	queue.push(s);

	auto safe = [f](const ll curr) -> bool {
		return (1 <= curr && curr <= f);
	};

	while (!queue.empty()) {
		ll curr = queue.front(); queue.pop();

		if (safe(curr+u) && dist[curr+u] > dist[curr] + 1) {
			dist[curr+u] = dist[curr] + 1;
			queue.push(curr+u);
		}

		if (safe(curr-d) && dist[curr-d] > dist[curr] + 1) {
			dist[curr-d] = dist[curr] + 1;
			queue.push(curr-d);
		}
	}

	if (dist[g] < INF) {
		cout << dist[g] << endl;
	} else {
		cout << "use the stairs" << endl;
	}

	return EXIT_SUCCESS;
}

