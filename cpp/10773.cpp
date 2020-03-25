#include <iostream>
#include <stack>

using namespace std;

using ull = unsigned long long;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	ull c;
	stack<ull> s;
	while (n--) {
		cin >> c;
		if (c != 0) {
			s.push(c);
		} else {
			s.pop();
		}
	}

	ull acc = 0;
	while (!s.empty()) {
		acc += s.top(); s.pop();
	}

	cout << acc << endl;

	return EXIT_SUCCESS;
}

