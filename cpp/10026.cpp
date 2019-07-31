#include <functional>
#include <iostream>
#include <vector>

using namespace std;


void dfs(int r, int c, int n, vector<string>& pic, vector<vector<bool>>& visited) {
    static const int dr[4] = {-1, 0, 1, 0};
    static const int dc[4] = {0, 1, 0, -1};

    static const function<bool(int, int)> safe = [&n](int row, int col) -> bool {
        return (0 <= row && row < n) && (0 <= col && col < n);
    };

    visited[r][c] = true;

    for (int i = 0; i < 4; ++i) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (safe(nr, nc) && !visited[nr][nc] && pic[nr][nc] == pic[r][c]) {
            dfs(nr, nc, n, pic, visited);
        }
    }
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> pic(n);
    for (int row = 0; row < n; ++row) {
        cin >> pic[row];
    }

    int cnt = 0;
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            if (!visited[r][c]) {
                dfs(r, c, n, pic, visited);
                ++cnt;
            }
        }
    }

    cout << cnt << ' ';

    for (string& row: pic) {
        for (char& r: row) {
            if (r == 'G') {
                r = 'R';
            }
        }
    }

    cnt = 0;
    visited.clear();
    visited.resize(n, vector<bool>(n, false));
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            if (!visited[r][c]) {
                dfs(r, c, n, pic, visited);
                ++cnt;
            }
        }
    }

    cout << cnt << endl;

    return EXIT_SUCCESS;
}

