#include <iostream>
#include <stack>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string line;
	while (getline(cin, line)) {
		if (line == ".") {
			break;
		}

		stack<char> s;
		bool balanced = true;
		for (auto c: line) {
			if (c == '(' || c == '[') {
				s.push(c);
			} else if (c == ')') {
				if (!s.empty() && s.top() == '(') {
					s.pop();
				} else {
					balanced = false;
					break;
				}
			} else if (c == ']') {
				if (!s.empty() && s.top() == '[') {
					s.pop();
				} else {
					balanced = false;
					break;
				}
			}
		}

		if (!s.empty()) {
			balanced = false;
		}

		cout << (balanced ? "yes" : "no") << '\n';
	}

	return EXIT_SUCCESS;
}

