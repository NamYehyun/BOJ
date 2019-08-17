#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    long long n;
    cin >> n;

    cout << (n / 5) + (n % 5 ? 1 : 0) << endl;

    return EXIT_SUCCESS;
}

