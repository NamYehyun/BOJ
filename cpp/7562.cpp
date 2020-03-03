#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int solve(void);

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int num_test;
	cin >> num_test;

	while (num_test--) {
		cout << solve() << '\n';
	}

	return EXIT_SUCCESS;
}

int solve(void) {
	const int INF = 0x7f7f7f7f;

	const int d = 8;
	const int dr[d] = {-2, -1, 1, 2, 2, 1, -1, -2};
	const int dc[d] = {-1, -2, -2, -1, 1, 2, 2, 1};

	int size;
	int srow, scol;  // source row, column
	int drow, dcol;  // destination row, colunm

	cin >> size;
	cin >> srow >> scol;
	cin >> drow >> dcol;

	queue<pair<int, int>> queue;
	vector<vector<int>> dist(size, vector<int>(size, INF));

	auto safe = [size](const int row, const int col) -> bool {
		return (0 <= row && row < size) && (0 <= col && col < size);
	};

	auto visited = [&dist](const int row, const int col) -> bool {
		return (dist[row][col] != INF);
	};

	dist[srow][scol] = 0;
	queue.push(make_pair(srow, scol));

	while (!queue.empty()) {
		auto [r, c] = queue.front(); queue.pop();
		for (int i = 0; i < d; ++i) {
			auto nr = r + dr[i];
			auto nc = c + dc[i];

			if (safe(nr, nc) && !visited(nr, nc)) {
				dist[nr][nc] = dist[r][c] + 1;
				queue.push(make_pair(nr, nc));
			}
		}
	}

	return dist[drow][dcol];
}

