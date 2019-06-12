#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int num_test;
    cin >> num_test;
    while (num_test--) {
        int v, e;
        cin >> v >> e;

        cout << 2 - v + e << '\n';
    }

    return EXIT_SUCCESS;
}

