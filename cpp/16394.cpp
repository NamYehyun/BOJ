#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    const int zero = 1946;

    int year;
    cin >> year;

    cout << year - zero << endl;

    return EXIT_SUCCESS;
}

