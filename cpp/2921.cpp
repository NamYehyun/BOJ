#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    long long n;
    cin >> n;

    cout << n * (n + 1) * (n + 2) / 2 << endl;

    return EXIT_SUCCESS;
}

