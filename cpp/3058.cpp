#include <iostream>

using namespace std;


const int INF = 0x7f7f7f7f;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int num_test;
    cin >> num_test;
    while (num_test--) {
        int acc = 0;
        int min = INF;
        for (int i = 0; i < 7; ++i) {
            int num;
            cin >> num;
            if (num % 2 == 0) {
                acc += num;
                if (num < min) {
                    min = num;
                }
            }
        }

        cout << acc << ' ' << min << '\n';
    }

    return EXIT_SUCCESS;
}

