#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    long long n;
    cin >> n;

    cout << ((n % 2 == 0) ? "CY" : "SK") << endl;

    return EXIT_SUCCESS;
}

