#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    long long a, b, c;
    cin >> a >> b >> c;

    long long sum = a + b;
    cout << ((sum >= 2*c) ? (sum - 2*c) : sum) << endl;

    return EXIT_SUCCESS;
}

