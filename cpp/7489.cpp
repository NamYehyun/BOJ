#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int num_test;
    cin >> num_test;
    while (num_test--) {
        int n;
        cin >> n;

        int fact = 1;
        for (int i = 1; i <= n; ++i) {
            fact = (fact * i) % 1000000;

            while (fact % 10 == 0) {
                fact /= 10;
            }
        }

        cout << fact % 10 << endl;
    }

    return EXIT_SUCCESS;
}

