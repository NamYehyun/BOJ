#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int num_hole, coverage;
    cin >> num_hole >> coverage;

    vector<int> holes(num_hole);
    for (int i = 0; i < num_hole; ++i) {
        cin >> holes[i];
    }

    sort(holes.begin(), holes.end());

    int idx = 0;
    int pos = 0;
    int cnt = 0;
    while (idx < num_hole) {
        if (pos < holes[idx]) {
            ++cnt;
            pos = holes[idx] + coverage - 1;
        }
        ++idx;
    }

    cout << cnt << endl;

    return EXIT_SUCCESS;
}

