#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    string bowls;
    cin >> bowls;

    const int length = bowls.length();

    int acc = 10;
    char curr = bowls[0];
    for (int i = 1; i < length; ++i) {
        if (bowls[i] == curr) {
            acc += 5;
        } else {
            acc += 10;
        }

        curr = bowls[i];
    }

    cout << acc << endl;

    return EXIT_SUCCESS;
}

