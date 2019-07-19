#include <iostream>
#include <vector>

using namespace std;


const int MAX = 20;


bool operator<(vector<int>& x, vector<int>& y) {
    int len_x = 0;
    int _len_x = x.size();
    while ((len_x < _len_x) && (x[len_x] >= 0)) {
        ++len_x;
    }

    int len_y = 0;
    int _len_y = y.size();
    while ((len_y < _len_y) && (y[len_y] >= 0)) {
        ++len_y;
    }

    if (len_x == len_y) {
        for (int i = 0; i < len_x; ++i) {
            if (x[i] < y[i]) {
                return true;
            }

            if (x[i] > y[i]) {
                return false;
            }
        }

        return false;
    }

    return len_x < len_y;
}


bool part(vector<int>& n, vector<int>& ans, pair<int, int>& rule, vector<int>& cnt, int used, int curr, int rear, bool enough) {
    if (curr > rear) {
        return true;
    }

    for (int i = (enough ? 0 : n[curr]); i <= 9; ++i) {
        if (used == rule.first && cnt[i] == 0) {
            continue;
        }

        if (cnt[i] < rule.second) {
            ans[curr] = i;
            cnt[i]++;

            if (part(n, ans, rule, cnt, used + (cnt[i] == 1), curr + 1, rear, enough || (n[curr] < i))) {
                return true;
            }
        }
    }

    if (1 <= curr) {
        --cnt[ans[curr-1]];
        ans[curr-1] = -1;
    }

    return false;
}


int main(void) {
    string n_str;
    cin >> n_str;

    int len = n_str.length();

    vector<int> n(MAX, -1);
    for (int i = 0; i < len; ++i) {
        n[i] = static_cast<int>(n_str[i] - '0');
    }

    vector<pair<int, int>> cases;
    for (int i = 1; (i <= 10) && (i <= len); ++i) {
        if (len % i == 0) {
            cases.emplace_back(i, len / i);
        }
    }

    vector<int> min_ans(MAX, 10);
    for (auto& c: cases) {
        vector<int> ans(MAX, -1);
        vector<int> cnt(10, 0);

        part(n, ans, c, cnt, 0, 0, len-1, false);

        if (ans[0] < 0) {
            continue;
        }

        if (ans < min_ans) {
            min_ans = ans;
        }
    }

    int idx = 0;
    while (min_ans[idx] >= 0) {
        cout << min_ans[idx];
        ++idx;
    }
    cout << endl;

    return EXIT_SUCCESS;
}

