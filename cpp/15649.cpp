#include <iostream>
#include <vector>

using namespace std;


void solve(int n, int m, int cnt, vector<int>& seq, vector<bool>& selected) {
    if (cnt == m) {
        for (int s: seq) {
            cout << s << ' ';
        }
        cout << '\n';

        return;
    }

    for (int next = 1; next <= n; ++next) {
        if (selected[next]) {
            continue;
        }

        seq.push_back(next);
        selected[next] = true;
        
        solve(n, m, cnt+1, seq, selected);

        seq.pop_back();
        selected[next] = false;
    }
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> seq;
    vector<bool> selected(n+1, false);
    solve(n, m, 0, seq, selected);

    return EXIT_SUCCESS;
}

