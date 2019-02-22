#include <iostream>
#include <vector>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;

    vector<vector<bool>> board(100, vector<bool>(100, false));

    for (int _ = 0; _ < n; ++_) {
        int x, y;
        cin >> x >> y;

        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                board[x+i][y+j] = true;
            }
        }
    }

    int area = 0;
    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 100; ++j) {
            if (board[i][j]) {
                ++area;
            }
        }
    }

    cout << area << endl;

    return EXIT_SUCCESS;
}

