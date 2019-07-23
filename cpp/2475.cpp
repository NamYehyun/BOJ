#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int acc = 0;
    for (int i = 0; i < 5; ++i) {
        int x;
        cin >> x;

        acc += x*x;
    }

    cout << acc % 10 << endl;

    return EXIT_SUCCESS;
}

