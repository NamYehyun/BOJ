#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    while (true) {
        int a, b;
        cin >> a >> b;

        if (!a && !b) {
            break;
        }

        cout << (a > b ? "Yes" : "No") << endl;
    }

    return EXIT_SUCCESS;
}

