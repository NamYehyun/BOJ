#include <iostream>
#include <queue>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	queue<int> q;
	for (int i = 1; i <= n; ++i) {
		q.push(i);
	}

	int last = -1;
	bool push = false;
	while (!q.empty()) {
		last = q.front(); q.pop();
		if (push) {
			q.push(last);
		}
		push = !push;
	}

	cout << last << endl;

	return EXIT_SUCCESS;
}

