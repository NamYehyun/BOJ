#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int num_test;
    cin >> num_test;
    while (num_test--) {
        long long n;
        cin >> n;

        long long acc = 0;
        for (int i = 0; i < 6; ++i) {
            long long a;
            cin >> a;
            acc += a;
        }

        long long day = 1;
        while (true) {
            if (acc > n) {
                break;
            }

            acc *= 4;
            day += 1;
        }

        cout << day << '\n';
    }

    return EXIT_SUCCESS;
}

