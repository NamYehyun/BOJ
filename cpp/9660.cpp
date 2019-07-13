#include <iostream>
#include <vector>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    long long n;
    cin >> n;

    cout << ((n % 7 == 0 || n % 7 == 2) ? "CY" : "SK") << endl;

    return EXIT_SUCCESS;
}

