#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int num_test;
    cin >> num_test;
    for (int test = 1; test <= num_test; ++test) {
        int a, b;
        cin >> a >> b;

        cout << "Case " << test << ": " << a + b << "\n";
    }

    return EXIT_SUCCESS;
}

