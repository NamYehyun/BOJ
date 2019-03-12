#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    while (true) {
        int x, y;
        cin >> x >> y;

        if (x == 0 && y == 0) {
            break;
        }

        bool factor = (y % x == 0);
        bool multiple = (x % y == 0);
        
        if (factor) {
            cout << "factor\n";
        } else if (multiple) {
            cout << "multiple\n";
        } else {
            cout << "neither\n";
        }
    }

    return EXIT_SUCCESS;
}

