#include <iostream>
#include <vector>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int row, col, max = 0;
    for (int i = 1; i <= 9; ++i) {
        for (int j = 1; j <= 9; ++j) {
            int num;
            cin >> num;

            if (max < num) {
                max = num;
                row = i;
                col = j;
            }
        }
    }

    cout << max << '\n' << row << ' ' << col << endl;

    return EXIT_SUCCESS;
}

