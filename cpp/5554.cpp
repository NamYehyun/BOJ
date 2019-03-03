#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int acc = 0;
    for (int i = 0; i < 4; ++i) {
        int t;
        cin >> t;
        acc += t;
    }

    cout << acc / 60 << endl;
    cout << acc % 60 << endl;

    return EXIT_SUCCESS;
}

