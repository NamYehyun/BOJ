#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    const int INF = 0x7f7f7f7f;

    int num_test;
    cin >> num_test;
    while (num_test--) {
        int n;
        cin >> n;

        int min = INF;
        int max = 0;

        for (int i = 0; i < n; ++i) {
            int pos;
            cin >> pos;
            min = (min < pos) ? min : pos;
            max = (max > pos) ? max : pos;
        }

        cout << 2*(max - min) << '\n';
    }

    return EXIT_SUCCESS;
}

