#include <iostream>

using namespace std;


const int MAX = 10000;


int main(void) {
    bool is_square_number[MAX+1] = {};
    for (int i = 1; i*i <= MAX; ++i) {
        is_square_number[i*i] = true;
    }

    int m, n;
    cin >> m >> n;

    int min = -1;
    int acc = 0;
    for (int i = m; i <= n; ++i) {
        if (is_square_number[i]) {
            acc += i;

            if (min < 0) {
                min = i;
            }
        }
    }

    if (min < 0) {
        cout << "-1" << endl;
    } else {
        cout << acc << endl;
        cout << min << endl;
    }

    return EXIT_SUCCESS;
}

