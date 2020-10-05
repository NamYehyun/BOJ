#include <bits/stdc++.h>

using namespace std;

#define __NARG__(...)	__NARG_I_(__VA_ARGS__, __RSEQ_N())
#define __NARG_I_(...)	__ARG_N(__VA_ARGS__)
#define __ARG_N(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, N, ...)	N
#define __RSEQ_N()	10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0

#define _VFUNC_(name, n)	name##n
#define _VFUNC(name, n)		_VFUNC_(name, n)
#define VFUNC(func, ...)	_VFUNC(func, __NARG__(__VA_ARGS__))(__VA_ARGS__)

#define idxmin(x)			(min_element(begin(x), end(x)) - begin(x))
#define idxmax(x)			(max_element(begin(x), end(x)) - begin(x))
#define idxlb(x, a)			(lower_bound(begin(x), end(x), a) - begin(x))
#define idxub(x, a)			(upper_bound(begin(x), end(x), a) - begin(x))

#define max(...)			VFUNC(MAX, __VA_ARGS__)
#define MAX1(x)				(x[idxmax(x)])
#define MAX2(a, b)			((a) > (b) ? (a) : (b))
#define MAX3(a, b, c)		(MAX2(MAX2((a), (b)), (c)))
#define MAX4(a, b, c, d)	(MAX2(MAX3((a), (b), (c)), (d)))

#define min(...)			VFUNC(MIN, __VA_ARGS__)
#define MIN1(x)				(x[idxmin(x)])
#define MIN2(a, b)			((a) < (b) ? (a) : (b))
#define MIN3(a, b, c)		(MIN2(MIN2((a), (b)), (c)))
#define MIN4(a, b, c, d)	(MIN2(MIN3((a), (b), (c)), (d)))

#define get(...)			VFUNC(GET, __VA_ARGS__)
#define GET1(x)				do { cin >> x; } while (false)
#define GET2(x, n)			do { x.resize(n); for (auto& a: x) cin >> a; } while (false)
#define GET3(x, nr, nc)		do { x.resize(nr); for (auto& row: x) { GET2(row, nc); } } while (false)

#define put(...)			VFUNC(PUT, __VA_ARGS__)
#define PUT1(x)				do { cout << x << '\n'; } while (false)

#ifdef ONLINE_JUDGE
#define DBG false
#else
#define DBG true
#endif

void _main(void) {
	int n, k;
	cin >> n >> k;

	string _num;
	cin >> _num;

	vector<int> num(n);
	for (int i = 0; i < n; ++i)
		num[i] = static_cast<int>(_num[i]-'0');

	vector<int> prev_idx(n, -1);
	vector<int> next_idx(n, -1);
	for (int i = 0; i < n-1; ++i) {
		prev_idx[i+1] = i;
		next_idx[i] = i+1;
	}

	int curr = 0;
	do {
		while (next_idx[curr] != -1 && num[curr] >= num[next_idx[curr]])
			curr = next_idx[curr];

		if (next_idx[curr] == -1) {
			num[curr] = -1;
			next_idx[prev_idx[curr]] = -1;
			curr = prev_idx[curr];
		} else {
			num[curr] = -1;
			if (prev_idx[curr] != -1 && next_idx[curr] != -1) {
				next_idx[prev_idx[curr]] = next_idx[curr];
				prev_idx[next_idx[curr]] = prev_idx[curr];
				curr = prev_idx[curr];
			} else if (prev_idx[curr] == -1) {
				prev_idx[next_idx[curr]] = -1;
				curr = next_idx[curr];
			} else if (next_idx[curr] == -1) {
				next_idx[prev_idx[curr]] = -1;
				curr = prev_idx[curr];
			}
		}
	} while (--k);

	for (int i = 0; i < n; ++i) {
		if (num[i] != -1) cout << num[i];
	}
	cout << '\n';

	return;
}

int main(void) {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1; // cin >> t;
	do {
		_main();
	} while (--t);

	return EXIT_SUCCESS;
}

