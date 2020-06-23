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
	long long k, n;
	cin >> k >> n;

	vector<long long> len;
	get(len, k);

	long long ans = 0;

	long long lo = 1;
	long long hi = max(len);
	while (lo <= hi) {
		long long mid = lo + (hi - lo)/2;

		long long cnt = 0;
		for (const long long& l: len) {
			cnt += (l / mid);
		}

		if (cnt >= n) {
			ans = max(ans, mid);
			lo = mid + 1;
		} else {
			hi = mid - 1;
		}
	}

	cout << ans << endl;

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

