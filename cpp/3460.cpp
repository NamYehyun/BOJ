#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int num_test;
    cin >> num_test;

    while (num_test--) {
        int num;
        cin >> num;

        int idx = 0;
        while (num) {
            if (num % 2) {
                cout << idx << ' ';
            }

            num /= 2;
            ++idx;
        }
        cout << endl;
    }

    return EXIT_SUCCESS;
}

