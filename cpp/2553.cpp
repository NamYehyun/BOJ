#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    long long n;
    cin >> n;

    long long fact = 1;
    for (long long i = 1; i <= n; ++i) {
        fact = (fact * i) % 10000000;

        while (fact % 10 == 0) {
            fact /= 10;
        }
    }

    cout << fact % 10 << endl;

    return EXIT_SUCCESS;
}

