#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int r, e, c;
        cin >> r >> e >> c;

        int benefit = e - c - r;
        if (0 < benefit) {
            cout << "advertise\n";
        } else if (0 == benefit) {
            cout << "does not matter\n";
        } else {
            cout << "do not advertise\n";
        }
    }

    return EXIT_SUCCESS;
}

