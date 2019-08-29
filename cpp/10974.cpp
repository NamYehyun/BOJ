#include <iostream>
#include <vector>

using namespace std;


void permute(const int n, vector<int>& seq, vector<bool>& used) {
    if (seq.size() == static_cast<size_t>(n)) {
        for (const auto& s: seq) {
            cout << s << ' ';
        }
        cout << '\n';
    } else {
        for (int i = 1; i <= n; ++i) {
            if (used[i]) {
                continue;
            }

            seq.push_back(i);
            used[i] = true;

            permute(n, seq, used);

            seq.pop_back();
            used[i] = false;
        }
    }

    return;
}


void permute(const int n) {
    vector<int> seq;
    vector<bool> used(n, false);

    permute(n, seq, used);

    return;
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;

    permute(n);

    return EXIT_SUCCESS;
}

