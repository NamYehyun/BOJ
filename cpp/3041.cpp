#include <iostream>
#include <map>
#include <vector>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    map<char, pair<int, int>> ans;

    for (char c = 'A'; c <= 'O'; ++c) {
        int row = (c-'A') / 4;
        int col = (c-'A') % 4;
        ans[c] = make_pair(row, col);
    }

    int acc = 0;
    for (int r = 0; r < 4; ++r) {
        string row;
        cin >> row;
        for (int c = 0; c < 4; ++c) {
            int piece = row[c];
            if (piece == '.') {
                continue;
            }

            acc += (abs(ans[piece].first - r) + abs(ans[piece].second - c));
        }
    }

    cout << acc << endl;

    return EXIT_SUCCESS;
}

