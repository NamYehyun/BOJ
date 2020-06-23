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
#define MIN1(x)				(x[idxmax(x)])
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

class Node {
public:
	int index, rank, next_rank;

	Node(int _index, int _rank, int _next_rank) {
		index = _index;
		rank = _rank;
		next_rank = _next_rank;
	}

	bool operator<(const Node& other) const {
		if (rank == other.rank) {
			return next_rank < other.next_rank;
		}

		return rank < other.rank;
	}
};

vector<int> get_suffix_array(const string& s) {
	const int length = static_cast<int>(s.length());

	vector<Node> nodes; nodes.reserve(length);
	for (int i = 0; i < length; ++i)
		nodes.emplace_back(i, s[i]-'a', ((i+1 < length) ? s[i+1]-'a' : -1));

	sort(nodes.begin(), nodes.end());

	vector<int> ind(length, -1);
	for (int len = 4; len < 2*length; len *= 2) {
		int rank = 0;
		int prev_rank = nodes[0].rank;
		nodes[0].rank = rank;
		ind[nodes[0].index] = 0;

		for (int i = 1; i < length; ++i) {
			if (!(nodes[i].rank == prev_rank && nodes[i].next_rank == nodes[i-1].next_rank)) {
				++rank;
			}

			prev_rank = nodes[i].rank;
			nodes[i].rank = rank;
			ind[nodes[i].index] = i;
		}

		for (int i = 0; i < length; ++i) {
			int next_index = nodes[i].index + len/2;
			nodes[i].next_rank = (next_index < length) ? nodes[ind[next_index]].rank : -1;
		}

		sort(nodes.begin(), nodes.end());
	}


	vector<int> suffix_array; suffix_array.reserve(length);
	for (const Node& n: nodes)
		suffix_array.emplace_back(n.index);

	return suffix_array;
}

vector<int> get_lcp_array(string& s, const vector<int>& suffix_array) {
	const int length = static_cast<int>(s.length());
	vector<int> lcp_array(length, 0);

	vector<int> inv_suffix_array(length);
	for (int i = 0; i < length; ++i)
		inv_suffix_array[suffix_array[i]] = i;

	int prev = 0;
	for (int i = 0; i < length; ++i) {
		if (inv_suffix_array[i] == length-1) {
			prev = 0;
		} else {
			int j = suffix_array[inv_suffix_array[i]+1];

			while (i + prev < length && j + prev < length && s[i + prev] == s[j + prev]) ++prev;

			lcp_array[inv_suffix_array[i]+1] = prev;

			if (prev > 0) --prev;
		}
	}

	return lcp_array;
}

void _main(void) {
	string s; cin >> s;

	vector<int> suffix_array = get_suffix_array(s);
	vector<int> lcp_array = get_lcp_array(s, suffix_array);

	long long ans = s.length()*(s.length() + 1)/2;
	for (const int& lcp: lcp_array) {
		ans -= static_cast<long long>(lcp);
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

