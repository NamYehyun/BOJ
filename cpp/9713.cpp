#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int num_test;
    cin >> num_test;
    while (num_test--) {
        int n;
        cin >> n;
        cout << ((n+1)/2)*((n+1)/2) << '\n';
    }

    return EXIT_SUCCESS;
}

