#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


class Line {
public:
    int l, r;

    Line(int _l, int _r): l(_l), r(_r) {}

    bool operator<(const Line& other) const {
        return l < other.l;
    }
};


int lis(vector<int>& seq, vector<int>& subseq) {
    const int n = seq.size();
    vector<int> prec(n);
    vector<int> memo(n+1);

    int len = 0;
    for (int i = 0; i < n; ++i) {
        int lo = 1;
        int hi = len;
        while (lo <= hi) {
            int mid = (lo + hi + 1) / 2;
            if (seq[memo[mid]] <= seq[i]) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        int new_len = lo;

        prec[i] = memo[new_len-1];
        memo[new_len] = i;

        if (new_len > len) {
            len = new_len;
        }
    }

    subseq.resize(len);
    int k = memo[len];
    for (int i = len-1; i >= 0; --i) {
        subseq[i] = seq[k];
        k = prec[k];
    }

    return len;
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;

    vector<Line> lines;
    lines.reserve(n);
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        lines.emplace_back(l, r);
    }

    sort(lines.begin(), lines.end());

    vector<int> seq;
    seq.reserve(n);
    for (const Line& line: lines) {
        seq.emplace_back(line.r);
    }

    vector<int> subseq;

    cout << n - lis(seq, subseq) << endl;

    int idx = 0;
    for (const Line& line: lines) {
        if (line.r == subseq[idx]) {
            ++idx;
        } else {
            cout << line.l << '\n';
        }
    }

    return EXIT_SUCCESS;
}

