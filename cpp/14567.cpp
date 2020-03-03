#include <iostream>
#include <vector>

using namespace std;

const int INF = 0x7f7f7f7f;

int solve(int v, vector<vector<int>>& prev, vector<int>& depth);

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int num_node, num_edge;
	cin >> num_node >> num_edge;

	vector<vector<int>> prev(num_node, vector<int>());
	for (int i = 0; i < num_edge; ++i) {
		int u, v;
		cin >> u >> v;
		prev[v-1].emplace_back(u-1);
	}

	vector<int> depth(num_node, INF);
	for (int i = 0; i < num_node; ++i) {
		cout << solve(i, prev, depth) << ' ';
	}
	cout << '\n';

	return EXIT_SUCCESS;
}

int solve(int v, vector<vector<int>>& prev, vector<int>& depth) {
	if (depth[v] < INF) {
		return depth[v];
	}

	depth[v] = 1;
	for (auto u: prev[v]) {
		depth[v] = max(depth[v], solve(u, prev, depth)+1);
	}

	return depth[v];
}

