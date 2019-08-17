#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int mm, dd;
    cin >> mm >> dd;

    if (mm < 2) {
        cout << "Before" << endl;
    } else if (mm == 2) {
        if (dd < 18) {
            cout << "Before" << endl;
        } else if (dd == 18) {
            cout << "Special" << endl;
        } else {
            cout << "After" << endl;
        }
    } else {
        cout << "After" << endl;
    }

    return EXIT_SUCCESS;
}

