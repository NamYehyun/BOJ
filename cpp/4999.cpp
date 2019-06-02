#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    string one, two;
    cin >> one >> two;

    cout << (one.length() >= two.length() ? "go" : "no") << endl;

    return EXIT_SUCCESS;
}

