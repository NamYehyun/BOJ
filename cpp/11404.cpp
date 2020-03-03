#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

const ll INF = 0x7f77777777;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	ll num_node, num_edge;
	cin >> num_node >> num_edge;

	vector<vector<ll>> dist(num_node, vector<ll>(num_node, INF));
	for (int i = 0; i < num_edge; ++i) {
		ll u, v, c;
		cin >> u >> v >> c;
		dist[u-1][v-1] = min(dist[u-1][v-1], c);
	}

	for (int u = 0; u < num_node; ++u) {
		dist[u][u] = 0;
	}

	for (int k = 0; k < num_node; ++k) {
		for (int i = 0; i < num_node; ++i) {
			for(int j = 0; j < num_node; ++j) {
				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}

	for (int i = 0; i < num_node; ++i) {
		for (int j = 0; j < num_node; ++j) {
			cout << (dist[i][j] < INF ? dist[i][j] : 0) << ' ';
		}
		cout << '\n';
	}

	return EXIT_SUCCESS;
}

