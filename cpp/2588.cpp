#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int a, b;
    cin >> a >> b;

    cout << a * (b % 10) << endl;
    cout << a * ((b / 10) % 10) << endl;
    cout << a * ((b / 100) % 10) << endl;
    cout << a * b << endl;

    return EXIT_SUCCESS;
}

