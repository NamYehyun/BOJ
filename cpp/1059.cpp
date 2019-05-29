#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int size;
    cin >> size;

    vector<int> lucky_set(size+1, 0);
    for (int i = 1; i <= size; ++i) {
        cin >> lucky_set[i];
    }

    sort(lucky_set.begin(), lucky_set.end());

    int num;
    cin >> num;

    for (int i = 0; i < size; ++i) {
        if (lucky_set[i] < num && num < lucky_set[i+1]) {
            cout << (num - lucky_set[i]) * (lucky_set[i+1] - num) - 1 << endl;
            return EXIT_SUCCESS;
        }
    }

    cout << 0 << endl;

    return EXIT_SUCCESS;
}

