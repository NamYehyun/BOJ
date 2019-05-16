#include <iostream>
#include <vector>

using namespace std;


void solve(const int& n, const int& m, int cnt, vector<int>& seq) {
    if (cnt == m) {
        for (int s: seq) {
            cout << s << ' ';
        }
        cout << '\n';

        return;
    }

    for (int i = 1; i <= n; ++i) {
        seq.push_back(i);
        solve(n, m, cnt+1, seq);
        seq.pop_back();
    }

    return;
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> seq;
    solve(n, m, 0, seq);

    return EXIT_SUCCESS;
}

