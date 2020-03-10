#include <iostream>
#include <vector>

using namespace std;

using ull = unsigned long long;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int num_tests;
	cin >> num_tests;
	while (num_tests--) {
		int n;
		cin >> n;

		vector<ull> s(n);
		vector<int> p(n);

		for (int i = 0; i < n; ++i) {
			cin >> s[i];
		}

		p[n-1] = n-1;
		for (int i = n-2; i >= 0; --i) {
			p[i] = (s[i] < s[p[i+1]]) ? p[i+1] : i;
		}

		ull acc = 0;
		for (int i = 0; i < n; ++i) {
			if (s[i] < s[p[i]]) {
				acc += (s[p[i]] - s[i]);
			}
		}

		cout << acc << '\n';
	}

	return EXIT_SUCCESS;
}

