#include <iostream>
#include <vector>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    vector<bool> taken(100+1, false);

    int n;
    cin >> n;

    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        int seat;
        cin >> seat;

        if (taken[seat]) {
            ++cnt;
        } else {
            taken[seat] = true;
        }
    }

    cout << cnt << endl;

    return EXIT_SUCCESS;
}

