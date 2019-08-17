#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    long long nrow, ncol, n;
    cin >> nrow >> ncol >> n;

    cout << ((nrow / n) + (nrow % n ? 1 : 0)) * ((ncol / n) + (ncol % n ? 1 : 0)) << endl;

    return EXIT_SUCCESS;
}

