#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    while (true) {
        int r;
        cin >> r;
        if (r == 0) {
            break;
        }

        int w, h;
        cin >> w >> h;

        cout << "Pizza " << t << " " << ((4*r*r >= w*w + h*h) ? "fits" : "does not fit") << " on the table.\n";

        ++t;
    }

    return EXIT_SUCCESS;
}

