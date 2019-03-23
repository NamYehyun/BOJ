#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    while (true) {
        int a, b;
        cin >> a >> b;

        if (!(a | b)) {
            break;
        }

        cout << a + b << endl;
    }

    return EXIT_SUCCESS;
}

