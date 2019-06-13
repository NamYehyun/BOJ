#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;

    while (true) {
        int acc = 0;
        while (n) {
            int digit = n % 10;
            acc += digit * digit;
            
            n /= 10;
        }

        if (acc == 1) {
            cout << "HAPPY" << endl;
            break;
        }

        if (acc == 4) {
            cout << "UNHAPPY" << endl;
            break;
        }

        n = acc;
    }

    return EXIT_SUCCESS;
}

