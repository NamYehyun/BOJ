#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, -1, 0, 1};


int colourize(int r, int c, int id, vector<vector<int>>& map, int n) {
    int size = 1;
    map[r][c] = id;

    for (int i = 0; i < 4; ++i) {
        int row = r + dr[i];
        int col = c + dc[i];
        if ((0 <= row && row < n) && (0 <= col && col < n) && map[row][col] == -1) {
            size += colourize(row, col, id, map, n);
        }
    }

    return size;
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<vector<int>> map(n, vector<int>(n));
    for (int r = 0; r < n; ++r) {
        string line;
        cin >> line;
        for (int c = 0; c < n; ++c) {
            map[r][c] = (line[c] == '1') ? -1 : 0;
        }
    }

    int id = 1;
    vector<int> size;
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            if (map[r][c] == -1) {
                size.push_back(colourize(r, c, id, map, n));
                ++id;
            }
        }
    }

    sort(size.begin(), size.end());
    
    cout << id-1 << '\n';
    for (int s: size) {
        cout << s << '\n';
    }
    
    return EXIT_SUCCESS;
}

