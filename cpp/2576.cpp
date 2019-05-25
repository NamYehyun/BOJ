#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int acc_odd = 0;
    int min_odd = 0x7f7f7f7f;
    for (int i = 0; i < 7; ++i) {
        int num;
        cin >> num;
        if (num % 2 == 1) {
            acc_odd += num;
            min_odd = min(num, min_odd);
        }
    }

    if (acc_odd != 0) {
        cout << acc_odd << endl << min_odd << endl;
    } else {
        cout << -1 << endl;
    }

    return EXIT_SUCCESS;
}

