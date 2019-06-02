#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int num_test;
    cin >> num_test;
    while (num_test--) {
        string one, two;
        cin >> one >> two;

        int dist = 0;
        int len = one.length();
        for (int i = 0; i < len; ++i) {
            if (one[i] != two[i]) {
                ++dist;
            }
        }

        cout << "Hamming distance is " << dist << ".\n";
    }

    return EXIT_SUCCESS;
}

