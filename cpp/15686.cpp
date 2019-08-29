#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

const int INF = 0x3f3f3f3f;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> srcs;
    vector<pair<int, int>> dsts;
    for (int row = 0; row < n; ++row) {
        for (int col = 0; col < n; ++col) {
            int val;
            cin >> val;

            if (val == 1) {
                dsts.emplace_back(row, col);
            }

            if (val == 2) {
                srcs.emplace_back(row, col);
            }
        }
    }

    const int num_src = srcs.size();
    const int num_dst = dsts.size();

    vector<vector<int>> dist(num_src, vector<int>(num_dst));
    for (int i = 0; i < num_src; ++i) {
        int row_s, col_s;
        tie(row_s, col_s) = srcs[i];
        for (int j = 0; j < num_dst; ++j) {
            int row_d, col_d;
            tie(row_d, col_d) = dsts[j];

            dist[i][j] = abs(row_d - row_s) + abs(col_d - col_s);
        }
    }

    vector<bool> selected;
    for (int i = m; i < num_src; ++i) {
        selected.emplace_back(false);
    }

    for (int i = 0; i < m; ++i) {
        selected.emplace_back(true);
    }

    int ans = INF;
    do {
        int acc = 0;
        for (int j = 0; j < num_dst; ++j) {
            int min_dist = INF;
            for (int i = 0; i < num_src; ++i) {
                if (!selected[i]) {
                    continue;
                }

                min_dist = min(dist[i][j], min_dist);
            }
            acc += min_dist;
        }
        ans = min(acc, ans);
    } while (next_permutation(selected.begin(), selected.end()));

    cout << ans << endl;

    return EXIT_SUCCESS;
}

