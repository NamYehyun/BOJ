#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    vector<int> seq(9);
    for (int i = 0; i < 9; ++i) {
        cin >> seq[i];
    }

    vector<int> select {
        0, 0, 1, 1, 1, 1, 1, 1, 1
    };

    do {
        int acc = 0;
        for (int i = 0; i < 9; ++i) {
            acc += select[i] * seq[i];
        }

        if (acc == 100) {
            break;
        }

    } while (next_permutation(select.begin(), select.end()));

    for (int i = 0; i < 9; ++i) {
        if (select[i]) {
            cout << seq[i] << endl;
        }
    }

    return EXIT_SUCCESS;
}

