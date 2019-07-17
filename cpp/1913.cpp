#include <iostream>
#include <vector>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> board(n, vector<int>(n, -1));

    int r = (n-1)/2;
    int c = (n-1)/2;
    
    int dir = 0;
    const int dr[4] = {-1, 0, 1, 0};
    const int dc[4] = {0, 1, 0, -1};

    int W = 2;
    int w = 0;

    board[r][c] = 1;
    for (int i = 2; i <= n*n; ++i) {
        r += dr[dir];
        c += dc[dir];

        board[r][c] = i;
        ++w;

        if (w == W/2) {
            dir = (dir + 1) % 4;
            w = 0;

            ++W;
        }
    }

    int N;
    cin >> N;

    int N_r, N_c;
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            if (board[r][c] == N) {
                N_r = r + 1;
                N_c = c + 1;
            }

            cout << board[r][c] << ' ';
        }
        cout << '\n';
    }

    cout << N_r << ' ' << N_c << endl;
    

    return EXIT_SUCCESS;
}

