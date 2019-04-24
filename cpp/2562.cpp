#include <iostream>
#include <vector>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int max_idx = -1;
    int max_val = -1;
    vector<int> seq(9);
    for (int i = 0; i < 9; ++i) {
        cin >> seq[i];
        if (max_val < seq[i]) {
            max_val = seq[i];
            max_idx = i;
        }
    }

    cout << max_val << endl;
    cout << max_idx + 1 << endl;

    return EXIT_SUCCESS;
}

