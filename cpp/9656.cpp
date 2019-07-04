#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;

    cout << ((n % 2 == 0) ? "SK" : "CY") << endl;

    return EXIT_SUCCESS;
}

