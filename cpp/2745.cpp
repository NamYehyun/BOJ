#include <iostream>

using namespace std;

using ull = unsigned long long;

inline ull to_decimal(char x) {
	if ('0' <= x && x <= '9') {
		return static_cast<ull>(x-'0');
	} else {
		return static_cast<ull>(x-'A') + 10;
	}
}

int main(void) {
	int b;
	string num;

	cin >> num >> b;

	ull acc = 0;
	int len = static_cast<int>(num.length());
	for (int i = 0; i < len; ++i) {
		acc += to_decimal(num[i]);
		if (i != len-1) {
			acc *= b;
		}
	}

	cout << acc << endl;

	return EXIT_SUCCESS;
}

