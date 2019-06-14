#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int num_test;
    cin >> num_test;
    while (num_test--) {
        int n, k;
        cin >> n >> k;

        int acc = 0;
        for (int i = 0; i < n; ++i) {
            int num;
            cin >> num;
            acc += (num / k);
        }

        cout << acc << "\n";
    }

    return EXIT_SUCCESS;
}

