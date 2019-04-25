#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int a, b;
    cin >> a >> b;

    if (a < b) {
        cout << "<" << endl;
    } else if (a > b) {
        cout << ">" << endl;
    } else {
        cout << "==" << endl;
    }

    return EXIT_SUCCESS;
}

