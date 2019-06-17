#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int num_test;
    cin >> num_test;
    while (num_test--) {
        int a = 0;
        int b = 0;
        int c = 0;

        for (int i = 0; i < 10; ++i) {
            int num;
            cin >> num;

            if (a <= num) {
                c = b;
                b = a;
                a = num;
            } else if (b <= num) {
                c = b;
                b = num;
            } else if (c <= num) {
                c = num;
            }
        }

        cout << c << '\n';
    }

    return EXIT_SUCCESS;
}

