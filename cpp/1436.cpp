#include <iostream>

using namespace std;

using ull = unsigned long long;

bool is_doom(ull x) {
	while (x) {
		if (x % 1000 == 666) {
			return true;
		}
		x /= 10;
	}

	return false;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	int i = 0;
	ull num = 0;
	while (i < n) {
		++num;
		if (is_doom(num)) {
			++i;
		}
	}

	cout << num << endl;
	
	return EXIT_SUCCESS;
}

