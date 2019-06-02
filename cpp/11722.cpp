#include <iostream>
#include <vector>

using namespace std;


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
            if (seq[memo[mid]] < seq[i]) {
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
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> seq, subseq;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        seq.push_back(-num);
    }

    cout << lis(seq, subseq) << endl;

    return EXIT_SUCCESS;
}

