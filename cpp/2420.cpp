#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    long long a, b;
    cin >> a >> b;

    cout << (a < b ? (b - a) : (a - b)) << endl;

    return EXIT_SUCCESS;
}

