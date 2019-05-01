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
    vector<int> p(n);
    vector<int> m(n+1);

    int l = 0;
    for (int i = 0; i < n; ++i) {
        int lo = 1;
        int hi = l;
        while (lo <= hi) {
            int mid = (lo + hi + 1) / 2;
            if (seq[m[mid]] <= seq[i]) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        int newL = lo;

        p[i] = m[newL-1];
        m[newL] = i;

        if (newL > l) {
            l = newL;
        }
    }

    subseq.resize(l);
    int k = m[l];
    for (int i = l-1; i >= 0; --i) {
        subseq[i] = seq[k];
        k = p[k];
    }

    return l;
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;

    vector<Line> lines;
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        lines.emplace_back(l, r);
    }

    sort(lines.begin(), lines.end());

    vector<int> seq;
    for (Line& line: lines) {
        seq.push_back(line.r);
    }

    vector<int> subseq;

    cout << n - lis(seq, subseq) << endl;

    return EXIT_SUCCESS;
}

