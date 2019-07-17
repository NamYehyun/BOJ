#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    unsigned long long n;
    cin >> n;

    cout << (((n - 1) * n) / 2) * (n + 1) << endl;

    return EXIT_SUCCESS;
}

