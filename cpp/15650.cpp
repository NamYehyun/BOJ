#include <iostream>
#include <vector>

using namespace std;


void solve(const int& n, const int& m, int i, int cnt, vector<int>& seq) {
    if (cnt == m) {
        for (int s: seq) {
            cout << s << ' ';
        }
        cout << '\n';

        return;
    }

    if (n < i) {
        return;
    }

    seq.push_back(i); ++cnt;
    solve(n, m, i+1, cnt, seq);

    seq.pop_back(); --cnt;
    solve(n, m, i+1, cnt, seq);

    return;
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;

    vector<int> seq;
    solve(n, m, 1, 0, seq);

    return EXIT_SUCCESS;
}

